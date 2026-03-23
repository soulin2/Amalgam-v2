#include "../SDK/SDK.h"

#include "../Features/Visuals/Visuals.h"
#include "../Features/Ticks/Ticks.h"
#include "../Features/CritHack/CritHack.h"
#include "../Features/Visuals/SpectatorList/SpectatorList.h"
#include "../Features/Backtrack/Backtrack.h"
#include "../Features/Visuals/PlayerConditions/PlayerConditions.h"
#include "../Features/NoSpread/NoSpreadHitscan/NoSpreadHitscan.h"
#include "../Features/Aimbot/Aimbot.h"
#include "../Features/Visuals/ESP/ESP.h"
#include "../Features/Visuals/OffscreenArrows/OffscreenArrows.h"
#include "../Features/Visuals/CameraWindow/CameraWindow.h"
#include "../Features/Visuals/Notifications/Notifications.h"
#include "../Features/NavBot/NavBotCore.h"
#include "../Features/Aimbot/AutoHeal/AutoHeal.h"
#include "../Features/Misc/AutoQueue/AutoQueue.h"
#include "../Features/Visuals/Chams/Chams.h"
#include "../Features/Visuals/Glow/Glow.h"
#include "../Features/Visuals/Materials/Materials.h"

MAKE_HOOK(IEngineVGui_Paint, U::Memory.GetVirtual(I::EngineVGui, 14), void,
	void* rcx, int iMode)
{
	DEBUG_RETURN(IEngineVGui_Paint, rcx, iMode);

	if (G::Unload)
		return CALL_ORIGINAL(rcx, iMode);

	F::AutoQueue.Run();

#ifndef TEXTMODE
	// Safety: reset all cheat render state before VGUI panels render.
	// This covers both "stuck m_bRendering" flags (e.g. exception in DrawModel)
	// AND cases where m_bRendering is already false but a material override or
	// render state was left dirty by a partial glow pass (e.g. SecondEnd crash,
	// or RenderViewmodel which never sets m_bRendering).
	// Doing this unconditionally is safe because 3D rendering is complete by the
	// time IEngineVGui::Paint fires.
	F::Chams.m_bRendering = false;
	F::Glow.m_bRendering = false;
	I::ModelRender->ForcedMaterialOverride(nullptr);
	if (auto pRenderContext = I::MaterialSystem->GetRenderContext())
	{
		pRenderContext->SetStencilEnable(false);
		pRenderContext->DepthRange(0.f, 1.f);
		pRenderContext->CullMode(MATERIAL_CULLMODE_CCW);
	}
#endif

	CALL_ORIGINAL(rcx, iMode);

	if (iMode & PAINT_INGAMEPANELS && !SDK::CleanScreenshot())
	{
		H::Draw.UpdateScreenSize();
		H::Draw.UpdateW2SMatrix();
		H::Draw.Start(true);
		if (auto pLocal = H::Entities.GetLocal())
		{
			F::CameraWindow.Draw();
			F::Visuals.DrawAntiAim(pLocal);

			F::Visuals.DrawPickupTimers();
			F::ESP.Draw();
			F::Arrows.Draw(pLocal);
			F::Aimbot.Draw(pLocal);

#ifdef DEBUG_VACCINATOR
			F::AutoHeal.Draw(pLocal);
#endif
			F::NoSpreadHitscan.Draw(pLocal);
			F::PlayerConditions.Draw(pLocal);
			F::Backtrack.Draw(pLocal);
			F::SpectatorList.Draw(pLocal);
			F::CritHack.Draw(pLocal);
			F::NavBotCore.Draw(pLocal);
			F::Ticks.Draw(pLocal);
			F::Visuals.DrawDebugInfo(pLocal);
		}
		H::Draw.End();
	}

	if (iMode & PAINT_UIPANELS && !SDK::CleanScreenshot())
	{
		H::Draw.UpdateScreenSize();
		H::Draw.Start();
		{
			F::Notifications.Draw();
		}
		H::Draw.End();
	}
}

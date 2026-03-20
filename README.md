<div align="center">

  ## <img src=".github/assets/amalgam_combo.png" alt="Amalgam" height="100">

  <sub>AVX2 may be faster than SSE2 though not all CPUs support it (`Steam > Help > System Information > Processor Information > AVX2`). Freetype uses freetype as the text rasterizer and includes some custom fonts, which results in better looking text but larger DLL sizes. PDBs are for developer use. </sub>
  ##
  
Read about the original Amalgam documentation and features [here](https://github.com/rei-2/Amalgam/wiki).  
Note: This repository is based on **TheGameEnhancer2004's fork** of Amalgam and includes additional changes and improvements.

**Thanks @mlemlody for the crashfix.**

*If you find this fork useful, please consider starring it. It really keeps me motivated and makes me feel like I'm not working on this alone!*
</div>

## Changes I've Made

- Added **Smart Airblast** (Experimental) Automatically prioritizes reflecting lethal and critical projectiles.
- Added Sniper **Triggerbot Detection**: Analyzes reaction times to detect instant headshots on enemies peeking while scoped.
- Added Legit Mode for **Auto-Detonate** (Requires Line-of-Sight).
- Added Projectile Filtering for **Auto-Airblast**.
- Fixed **Auto-Crossbow** interrupting active UberCharges.
- Improved **Crossbow Auto-switch**: Added invulnerability check.
- Fixed **Auto Detonate** triggering unwanted airblasts during weapon switch.
- Fixed **Lag-compensation** abuse false positives.
- Optimized **SmoothVelocity** to prevent FPS drops.
- Changed default value of **Auto Abandon if no navmesh** to `false`.
- Improved **Projectile Aimbot**: Added exponential drag decay and dynamic ToF-based smoothing.
- Fixed Rescue Ranger **Auto-Repair** aim height and added per-building type filtering.

> **Integrated 11 Neo64 Core Features:**
> *   **Adaptive Resolver:** Learns from misses to fix enemy fake angles.
> *   **Swing Prediction:** Perfect timing for melee attacks.
> *   **ThreadPool:** Multi-threaded performance optimization.
> *   **Aim Smoothing:** More natural, human-like aim movement.
> *   **New Infrastructure:** Refactored Hooking, Config, and Event systems.
> **- Modernized Core Architecture:**
> *   **Hash-based NetVars:** Replaced string lookups with compile-time FNV1A hashing for 0ms overhead.
> *   **Lifecycle Management:** Standardized feature initialization using `HasLoad`, `HasUnload`, and `InstTracker`.
> *   **Performance:** Faster game event handling and memory management via `MAKE_UNIQUE`.


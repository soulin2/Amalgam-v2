<div align="center">

  ## <img src=".github/assets/amalgam_combo.png" alt="Amalgam" height="100">

  <sub>AVX2 may be faster than SSE2 though not all CPUs support it (`Steam > Help > System Information > Processor Information > AVX2`). Freetype uses freetype as the text rasterizer and includes some custom fonts, which results in better looking text but larger DLL sizes. PDBs are for developer use. </sub>
  ##
  
Read about the original Amalgam documentation and features [here](https://github.com/rei-2/Amalgam/wiki).  
Note: This repository is based on **TheGameEnhancer2004's fork** of Amalgam and includes additional changes and improvements.

**Thanks @mlemlody for the crashfix.**
  
## Changes I've Made

- Added **Smart Airblast**. (Sometimes works EXPERIMENTAL) automatically airblasts incoming critical projectiles.
- Added **Sniper Triggerbot Detection** to Cheater Detection. Detects players who instantly headshot enemies peeking while scoped. headshot timing.
- Added **Legit Mode** Auto-Detonate. Automatically detonates explosives when enemies are in direct line-of-sight.
- Added **Select Projectiles Auto-Airblast**.
- Improved **Auto-switch Crossbow logic** to avoid interrupting Uber.
- Optimized **SmoothVelocity** to prevent FPS drops.
- Improved **Auto-Airblast Redirect**.
- Improved **Auto Detonate**.
- Fixed **Medic Auto-arrow shoots like silent aimbot and FOV bypass**.
- Fixed **Lag-compensation abuse false positives**.



### Changes
- Changed default value of **Auto Abandon if no navmesh** to `false`.



### Cleanup
- Cleaned up **README**.

</div>

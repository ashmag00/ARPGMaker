# ARPGMaker
ARPG Game Engine for COS370

## Build and Run
NOTE: Requires Python 3.7
To build the ARPGMaker module:
```
$ make build
```
To run the game:
```
$ make run
```

## Features
- Map
  - Adjustable tile system
    - Background loading
  - Camera
    - Displays dimensions for number of tiles
- Entity class
  - Player, NPCs/Enemies
  - Animations (Basic)
- Rendering
  - Render layers of ground, textures, players/buildings on each tile
- GUI
  - Menu helper functions
- Audio

## Versions
- 1.0
  - Player object
    - Take input
    - Movement
  - Load .png for background

### Issues
- Textures require rendering and drawing in the same scope
- Drawable is pur virtual, so no buffer of Drawables

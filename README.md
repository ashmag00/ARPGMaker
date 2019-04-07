# ARPGMaker
ARPG Game Engine for COS370

## Build and Run
NOTE: Requires Python 3.7
To build the ARPGMaker module:
```
$ python3.7 setup.py build
```
To run the game:
```
$ python3.7 <path/to/game.py>
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
# ARPGMaker
ARPG Game Engine for COS370

## Build and Run
NOTE: Requires Python 3.7

1. Build the ARPGMaker module:
```
$ make build
```
2. Update the Makefile to point to your `game.py`

3. Run the game:
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

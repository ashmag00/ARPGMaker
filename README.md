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

## Versions
- 1.0
  - Player object
    - Take input
    - Movement
  - Load .png for background

## Issues
- Textures require rendering and drawing in the same scope
- sf::Drawable is pure virtual, so no buffer of Drawables

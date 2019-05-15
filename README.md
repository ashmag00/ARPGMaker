# ARPGMaker
ARPGMaker is a Python module that provides functionality for creating 2D action games using a custom C++ engine with subsystems, including audio and tile mapping.

## Build and Run
NOTE: Requires Python 3.7 and SFML

Build the ARPGMaker module:
```
$ make build
```
Clear the ARPGMaker module
```
$ make clean
```

## Available Functions
### Main
---
#### init(int resX, int resY, int tileSize, char *title)
Inits the engine with a screen resolution, tile size, and window title.

#### systemEventHandler()
Starts the handler for reading inputs.

#### close()
Closes the running window.

### Inputs
---
#### isKeyPressed(char *key)
Checks if a specified key is currently pressed.

#### mousePositionX()
Returns the mouse's X position.

#### mousePositionY()
Returns the mouse's Y position.

#### mouseLeftClick()
Determine whether the left click is pressed.

### Collision
---
#### circleCollide(int ent1ID, ent2ID)
Determines whether two Entities are colliding.

### Entity
---
#### createEntity(int posx, int posy, int radius)
Create an Entity object with a position and radius.

#### remEntity(int entID)
Remove an Entity from the internal entityList.

#### getEntityPositionX(int entID)
Returns the Entity's X position.

#### getEntityPositionY(int entID)
Returns the Entity's Y position.

#### move(unsigned int id, int movex, int movey)
Move an Entity in an X and Y direction.

#### movef(unsigned int id, int numx, int denx, int numy, int deny)
Move an Entity in an X and Y direction precisely.

### Render
---
#### isOpen()
Determines whether the window is open.

#### loadTexture(char *filePath)
Stores a texture in the local texture hash  to use later.

#### setTexture(unsigned int id, char *texturePath)
Bind a texture to an Entity object.

#### setBackground(char *filePath)
Set the background texture.

#### renderImage(char *filePath)
Attach a loaded texture to a sprite and store it in the draw buffer.

#### renderEntity(unsigned int id)
Attach the Entity's texture to a sprite and store it in the draw buffer.

#### renderEntities()
Attach all Entity textures to sprites and store them in the draw buffer.

#### renderBackground()
Attaches the background texture to a sprite and stores it in the draw buffer.

#### draw()
Draw everything in the draw buffer.

#### display()
Displays all drawn objects to the screen.

#### clear()
Clear the screen to all black.

### Music
---
#### createMusic(char *fileName)
Constructs a Music object.

#### playMusic(int ID)
Plays audio of Music object. Resumes audio of a paused Music object.

#### pauseMusic(int ID)
Pauses audio of Music object; keeps playback point at pause point.

#### stopMusic(int ID)
Stops audio of Music object; sets playback point at beginning of audio.

#### setMusicLoop(int ID, int setting)
Sets loop setting for audio playback. Default setting is to not loop.

#### setMusicVolume(int ID, unsigned int vol)
Adjusts playback volume of Music object.

#### setMusicPitch(int ID, int pitch)
Adjusts playback pitch of Music object. NOTE: adjusting pitch also affects playback speed.

#### getMusicStatus(int ID)
Get the current status of the Music.

### Sound
---
#### createSound(char *fileName)
Constructs a Sound object.

#### setBuffer(int ID, int bufferID)
Sets a Sound object to use the buffer of another Sound object.

#### playSound(int ID)
Plays audio of Sound object. Resumes audio of a paused Sound object.

#### pauseSound(int ID)
Pauses audio of Sound object; keeps playback point at pause point.

#### stopSound(int ID)
Stops audio of Sound object; sets playback point at beginning of audio.

#### setSoundLoop(int ID, int setting)
Sets loop setting for audio playback. Default setting is to not loop.

#### setSoundVolume(int ID, unsigned int vol)
Adjusts playback volume of Sound object.

#### setSoundPitch(int ID, int pitch)
Adjusts playback pitch of Sound object. NOTE: adjusting pitch also affects playback speed.

#### getSoundStatus(int ID)
Get the current status of the Sound.

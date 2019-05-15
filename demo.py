import ARPGMaker
import time

DEBUG = False

# Start the engine
ARPGMaker.init(800, 600, 32, "ARPGMaker Demo Using C++")

# Store textures
ARPGMaker.loadTexture("assets/testBack.png")
ARPGMaker.loadTexture("assets/pikachu.png")

playerID = ARPGMaker.createEntity(200, 200, 50)
player2 = ARPGMaker.createEntity(400, 400, 50)
ARPGMaker.setTexture(playerID, "assets/pikachu.png")
ARPGMaker.setTexture(player2, "assets/pikachu.png")

# Load and play music (larger audio)
'''bgMusic = ARPGMaker.createMusic("assets/parry.wav")
ARPGMaker.setMusicLoop(bgMusic,1)
ARPGMaker.setMusicVolume(bgMusic,50)
ARPGMaker.setMusicPitch(bgMusic,50)
ARPGMaker.playMusic(bgMusic)'''
# Load and play sound (smaller audio)
'''source = ARPGMaker.createSound("assets/parry.wav",1)
sound2 = ARPGMaker.createSound("assets/parry.wav",0)
ARPGMaker.setBuffer(sound2,source)
ARPGMaker.setSoundLoop(sound2,1)
ARPGMaker.setSoundVolume(sound2,10)
ARPGMaker.setSoundPitch(sound2,150)
ARPGMaker.playSound(sound2)'''


while ARPGMaker.isOpen():

    ARPGMaker.systemEventHandler()

    if ARPGMaker.isKeyPressed('W') == 1:
        ARPGMaker.move(playerID, 0, -10)
    if ARPGMaker.isKeyPressed('S') == 1:
        ARPGMaker.move(playerID, 0, 10)
    if ARPGMaker.isKeyPressed('A') == 1:
        ARPGMaker.move(playerID, -10, 0)
    if ARPGMaker.isKeyPressed('D') == 1:
        ARPGMaker.move(playerID, 10, 0)

    ARPGMaker.clear()

    ARPGMaker.renderImage("assets/testBack.png")
    ARPGMaker.renderEntities()
    
    ARPGMaker.draw()
    ARPGMaker.display()

    if ARPGMaker.getEntityPositionX(playerID) == 400:
        ARPGMaker.remEntity(player2)

ARPGMaker.close()

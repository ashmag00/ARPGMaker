import ARPGMaker
import time

DEBUG = False

# Start the engine
ARPGMaker.init(800, 600, 64, "Gabe's ARPGMaker Demo Using C++")

# Store textures
ARPGMaker.loadTexture("gabe_assets/testBack-128.png")
ARPGMaker.loadTexture("gabe_assets/pikachu.png")
ARPGMaker.loadTexture("gabe_assets/squirtle-scaled.png")
ARPGMaker.loadTexture("gabe_assets/bullet-scaled.png")

ARPGMaker.setBackground("gabe_assets/testBack-128.png")

player1 = ARPGMaker.createEntity(350, 400, 50)
ARPGMaker.setTexture(player1, "gabe_assets/squirtle-scaled.png")


enemy1 = ARPGMaker.createEntity(100, 200, 50)
enemy2 = ARPGMaker.createEntity(250, 50, 50)
enemy3 = ARPGMaker.createEntity(425, 50, 50)
enemy4 = ARPGMaker.createEntity(575, 200, 50)
ARPGMaker.setTexture(enemy1, "gabe_assets/squirtle-scaled.png")
ARPGMaker.setTexture(enemy2, "gabe_assets/squirtle-scaled.png")
ARPGMaker.setTexture(enemy3, "gabe_assets/squirtle-scaled.png")
ARPGMaker.setTexture(enemy4, "gabe_assets/squirtle-scaled.png")

e1 = ARPGMaker.createSound("gabe_assets/note.wav",1)
e2 = ARPGMaker.createSound("gabe_assets/note.wav",0)
e3 = ARPGMaker.createSound("gabe_assets/note.wav",0)
e4 = ARPGMaker.createSound("gabe_assets/note.wav",0)
ARPGMaker.setBuffer(e2,e1)
ARPGMaker.setBuffer(e3,e1)
ARPGMaker.setBuffer(e4,e1)
ARPGMaker.setSoundVolume(e1,80)
ARPGMaker.setSoundVolume(e2,80)
ARPGMaker.setSoundVolume(e3,80)
ARPGMaker.setSoundVolume(e4,80)
ARPGMaker.setSoundPitch(e1,33)
ARPGMaker.setSoundPitch(e2,66)
ARPGMaker.setSoundPitch(e3,99)
ARPGMaker.setSoundPitch(e4,132)
ARPGMaker.playSound(e1)

t0 = time.time()


def update():
    return

while ARPGMaker.isOpen():
    ARPGMaker.systemEventHandler()
    time.sleep(1/60)

    if ARPGMaker.isKeyPressed('W') == 1:
        ARPGMaker.move(player1, 0, -10)
    if ARPGMaker.isKeyPressed('S') == 1:
        ARPGMaker.move(player1, 0, 10)
    if ARPGMaker.isKeyPressed('A') == 1:
        ARPGMaker.move(player1, -10, 0)
    if ARPGMaker.isKeyPressed('D') == 1:
        ARPGMaker.move(player1, 10, 0)

    if ( ARPGMaker.circleCollide(player1,enemy1) and ARPGMaker.getSoundStatus(e1) == 0 ):
        ARPGMaker.playSound(e1)
    if ( ARPGMaker.circleCollide(player1,enemy2) and ARPGMaker.getSoundStatus(e2) == 0 ):
        ARPGMaker.playSound(e2)
    if ( ARPGMaker.circleCollide(player1,enemy3) and ARPGMaker.getSoundStatus(e3) == 0 ):
        ARPGMaker.playSound(e3)
    if ( ARPGMaker.circleCollide(player1,enemy4) and ARPGMaker.getSoundStatus(e4) == 0 ):
        ARPGMaker.playSound(e4)
        

    ARPGMaker.clear()
    ARPGMaker.renderBackground()
    ARPGMaker.renderEntities()
    ARPGMaker.draw()
    ARPGMaker.display()

ARPGMaker.close()
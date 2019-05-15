import ARPGMaker
import time

DEBUG = False

# Start the engine
ARPGMaker.init(800, 600, 64, "Gabe's ARPGMaker Demo Using C++")

# Store textures
ARPGMaker.loadTexture("gabe_assets/testBack-128.png")
ARPGMaker.loadTexture("gabe_assets/pikachu-scaled.png")
ARPGMaker.loadTexture("gabe_assets/pikachu-scaled2.png")
ARPGMaker.loadTexture("gabe_assets/squirtle-scaled.png")
ARPGMaker.loadTexture("gabe_assets/jigglypuff.png")
ARPGMaker.loadTexture("gabe_assets/minun.png")
ARPGMaker.loadTexture("gabe_assets/plusle.png")

ARPGMaker.setBackground("gabe_assets/testBack-128.png")

# Entities
player1 = ARPGMaker.createEntity(350, 275, 50)
ARPGMaker.setTexture(player1, "gabe_assets/squirtle-scaled.png")
button1 = ARPGMaker.createEntity(50, 450, 50)
button2 = ARPGMaker.createEntity(650, 450, 50)
ARPGMaker.setTexture(button1, "gabe_assets/minun.png")
ARPGMaker.setTexture(button2, "gabe_assets/plusle.png")
musicButton = ARPGMaker.createEntity(350, 450, 50)
ARPGMaker.setTexture(musicButton, "gabe_assets/jigglypuff.png")

enemy1 = ARPGMaker.createEntity(100, 200, 50)
enemy2 = ARPGMaker.createEntity(250, 50, 50)
enemy3 = ARPGMaker.createEntity(425, 50, 50)
enemy4 = ARPGMaker.createEntity(575, 200, 50)
ARPGMaker.setTexture(enemy1, "gabe_assets/pikachu-scaled2.png")
ARPGMaker.setTexture(enemy2, "gabe_assets/pikachu-scaled2.png")
ARPGMaker.setTexture(enemy3, "gabe_assets/pikachu-scaled2.png")
ARPGMaker.setTexture(enemy4, "gabe_assets/pikachu-scaled2.png")
enemyEntities = [enemy1,enemy2,enemy3,enemy4]

# Sounds
e1 = ARPGMaker.createSound("gabe_assets/note.wav",1)
e2 = ARPGMaker.createSound("gabe_assets/note.wav",0)
e3 = ARPGMaker.createSound("gabe_assets/note.wav",0)
e4 = ARPGMaker.createSound("gabe_assets/note.wav",0)
ARPGMaker.setBuffer(e2,e1)
ARPGMaker.setBuffer(e3,e1)
ARPGMaker.setBuffer(e4,e1)
ARPGMaker.setSoundPitch(e1,33)
ARPGMaker.setSoundPitch(e2,66)
ARPGMaker.setSoundPitch(e3,99)
ARPGMaker.setSoundPitch(e4,132)
ARPGMaker.setSoundVolume(e1,50)
ARPGMaker.setSoundVolume(e2,50)
ARPGMaker.setSoundVolume(e3,50)
ARPGMaker.setSoundVolume(e4,50)

db = ARPGMaker.createSound("gabe_assets/down-button.wav",1)
ub = ARPGMaker.createSound("gabe_assets/up-button.wav",1)
ARPGMaker.setSoundVolume(db, 50)
ARPGMaker.setSoundVolume(ub, 50)
ARPGMaker.setSoundPitch(db,75)
# Convenient lists
enemyVolumes = [50,50,50,50,50,50]
enemySounds = [e1,e2,e3,e4,db,ub]

# Music
bgMusic = ARPGMaker.createMusic("gabe_assets/shovel-music.wav")
ARPGMaker.setMusicVolume(bgMusic,50)


def pikachuPress(i):
    if ( ARPGMaker.circleCollide(player1,enemyEntities[i]) and ARPGMaker.getSoundStatus(enemySounds[i]) == 0  and ARPGMaker.isKeyPressed('P') == 1 ):
        return 1
    elif ( ARPGMaker.getSoundStatus(enemySounds[i]) == 0 ):
        return 0
    

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

    for i in range(len(enemyEntities)):
        if ( pikachuPress(i) == 1 ):
            ARPGMaker.setTexture(enemyEntities[i],"gabe_assets/pikachu-scaled.png")
            ARPGMaker.playSound(enemySounds[i])
        if ( pikachuPress(i) == 0 ):
            ARPGMaker.setTexture(enemyEntities[i],"gabe_assets/pikachu-scaled2.png")

    if ( ARPGMaker.circleCollide(player1,button1) and ARPGMaker.getSoundStatus(db) == 0 and ARPGMaker.isKeyPressed('P') == 1 ):
        for i in range(len(enemyVolumes)):
            if enemyVolumes[i] > 0:
                enemyVolumes[i] -= 10
                ARPGMaker.setSoundVolume(enemySounds[i],enemyVolumes[i])
                ARPGMaker.playSound(db)
    if ( ARPGMaker.circleCollide(player1,button2) and ARPGMaker.getSoundStatus(ub) == 0 and ARPGMaker.isKeyPressed('P') == 1 ):
        for i in range(len(enemyVolumes)):
            if enemyVolumes[i] < 100:
                enemyVolumes[i] += 10
                ARPGMaker.setSoundVolume(enemySounds[i],enemyVolumes[i])
                ARPGMaker.playSound(ub)
    
    if ( ARPGMaker.circleCollide(player1,musicButton) and ARPGMaker.isKeyPressed('P') == 1 ):
        if ( ARPGMaker.getMusicStatus(bgMusic) == 0 or ARPGMaker.getMusicStatus(bgMusic) == 1 ):
            ARPGMaker.playMusic(bgMusic)
        elif ( ARPGMaker.getMusicStatus(bgMusic) == 2 ):
            ARPGMaker.pauseMusic(bgMusic)

    ARPGMaker.clear()
    ARPGMaker.renderBackground()
    ARPGMaker.renderEntities()
    ARPGMaker.draw()
    ARPGMaker.display()

ARPGMaker.close()
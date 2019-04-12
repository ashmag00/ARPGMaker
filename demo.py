import ARPGMaker

DEBUG = False

ARPGMaker.init(800, 600, "ARPGMaker Demo Using C++")
ARPGMaker.loadTexture("assets/testBack.png")
ARPGMaker.loadTexture("assets/pikachu.png")

ARPGMaker.renderImage("assets/testBack.png")
ARPGMaker.renderImage("assets/pikachu.png")

# Eventually set to an actual condition
while True:
    ARPGMaker.systemEventHandler()

    if DEBUG:
        if ARPGMaker.isKeyPressed('W') == 1:
            print('W')
        if ARPGMaker.isKeyPressed('S') == 1:
            print('S')
        if ARPGMaker.isKeyPressed('A') == 1:
            print('A')
        if ARPGMaker.isKeyPressed('D') == 1:
            print('D')

    ARPGMaker.draw()
    ARPGMaker.display()

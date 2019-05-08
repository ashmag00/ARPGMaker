import ARPGMaker

DEBUG = False

# Start the engine
ARPGMaker.init(800, 600, 32, "ARPGMaker Demo Using C++")

# Store textures
assets = "assets/assets.txt"
# ARPGMaker.loadTexturesFromFile(assets)
ARPGMaker.loadTexture("assets/testBack.png")
ARPGMaker.loadTexture("assets/pikachu.png")

playerID = ARPGMaker.createEntity(200, 200, 50)
player2 = ARPGMaker.createEntity(400, 400, 50)
ARPGMaker.setTexture(playerID, "assets/pikachu.png")
ARPGMaker.setTexture(player2, "assets/pikachu.png")

# Eventually set to an actual condition
while ARPGMaker.isOpen():
    ARPGMaker.systemEventHandler()
    ARPGMaker.clear()

    if ARPGMaker.isKeyPressed('W') == 1:
        ARPGMaker.move(playerID, 0, -10)
    if ARPGMaker.isKeyPressed('S') == 1:
        ARPGMaker.move(playerID, 0, 10)
    if ARPGMaker.isKeyPressed('A') == 1:
        ARPGMaker.move(playerID, -10, 0)
    if ARPGMaker.isKeyPressed('D') == 1:
        ARPGMaker.move(playerID, 10, 0)

    ARPGMaker.renderImage("assets/testBack.png")
    ARPGMaker.renderEntity(playerID)
    ARPGMaker.renderEntity(player2)
    
    ARPGMaker.draw()
    ARPGMaker.display()

    if DEBUG:
        if ARPGMaker.isKeyPressed('W') == 1:
            print('W')
        if ARPGMaker.isKeyPressed('S') == 1:
            print('S')
        if ARPGMaker.isKeyPressed('A') == 1:
            print('A')
        if ARPGMaker.isKeyPressed('D') == 1:
            print('D')

ARPGMaker.close()

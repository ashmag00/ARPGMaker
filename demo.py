import ARPGMaker

from time import sleep

# ARPGMaker.printHello()

ARPGMaker.init(800, 600, "ARPGMaker Demo Using C++")
# ARPGMaker.renderImage("assets/testBack.png")
# ARPGMaker.renderImage("assets/pikachu.png")

while True:
    ARPGMaker.systemEventHandler()
    # if ARPGMaker.isKeyPressed('W') == 1:
    #     print('W')
    # if ARPGMaker.isKeyPressed('S') == 1:
    #     print('S')
    # if ARPGMaker.isKeyPressed('A') == 1:
    #     print('A')
    # if ARPGMaker.isKeyPressed('D') == 1:
    #     print('D')
    # ARPGMaker.draw()
    ARPGMaker.renderImage("assets/testBack.png")
    ARPGMaker.display()
# sleep(5)

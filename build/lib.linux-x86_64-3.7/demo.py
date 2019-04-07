import ARPGMaker

ARPGMaker.printHello()

ARPGMaker.init(800, 600, "ARPGMaker Demo Using C++")

while True:
    ARPGMaker.systemEventHandler()
    ARPGMaker.display()

exit()

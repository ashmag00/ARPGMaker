import ARPGMaker
import time

import draw

width = 800
height = 600
tile_size = 100
ARPGMaker.init(width, height, tile_size, "Noah's Hack 'n Slash")

ARPGMaker.loadTexture("assets/pikachu.png")
ARPGMaker.loadTexture("assets/squirtle.png")
ARPGMaker.loadTexture("assets/testBack.png")
ARPGMaker.setBackground("assets/testBack.png")

player_radius = 128
player = ARPGMaker.createEntity(400, 300, player_radius)
ARPGMaker.setTexture(player, "assets/pikachu.png")
attack = None

ARPGMaker.renderBackground()

update_start = time.time()
while ARPGMaker.isOpen():
    ARPGMaker.systemEventHandler()
    main_start = time.time()
    while (time.time() - main_start) < (1 / 60):
        update_delta = time.time() - update_start
        update_start = time.time()

        if ARPGMaker.isKeyPressed('W') == 1 and ARPGMaker.getEntityPositionY(player) > 0:
            ARPGMaker.movef(player, 0, 1, int(-500 * update_delta * 100), 100)
        if ARPGMaker.isKeyPressed('S') == 1 and ARPGMaker.getEntityPositionY(player) < height - player_radius:
            ARPGMaker.movef(player, 0, 1, int(500 * update_delta * 100), 100)
        if ARPGMaker.isKeyPressed('A') == 1 and ARPGMaker.getEntityPositionX(player) > 0:
            ARPGMaker.movef(player, int(-500 * update_delta * 100), 100, 0, 1)
        if ARPGMaker.isKeyPressed('D') == 1 and ARPGMaker.getEntityPositionX(player) < width - player_radius:
            ARPGMaker.movef(player, int(500 * update_delta * 100), 100, 0, 1)
        if ARPGMaker.mouseLeftClick():
            attack = ARPGMaker.createEntity(ARPGMaker.getEntityPositionX(player), ARPGMaker.getEntityPositionY(player) - player_radius, 20)
            ARPGMaker.setTexture(attack, "assets/squirtle.png")
            ARPGMaker.renderEntity(attack)
            print("ATTACK")

        # ARPGMaker.renderImage("assets/testBack.png")
        if attack is not None:
            ARPGMaker.remEntity(attack)
            print("REMOVED")
            attack = None
                
        draw.draw_all()

ARPGMaker.close()

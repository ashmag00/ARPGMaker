import ARPGMaker
import time
import random

import draw

width = 1000
height = 600
tile_size = 128
ARPGMaker.init(width, height, tile_size, "Noah's Hack 'n Slash")

ARPGMaker.loadTexture("assets/pikachu.png")
ARPGMaker.loadTexture("assets/squirtle.png")
ARPGMaker.loadTexture("assets/testBack-128.png")
ARPGMaker.setBackground("assets/testBack-128.png")

player_radius = 64
player = ARPGMaker.createEntity(int(width / 2), int(height / 2), player_radius)
ARPGMaker.setTexture(player, "assets/pikachu.png")
attack = None

enemy = ARPGMaker.createEntity(0, 0, 100)
ARPGMaker.setTexture(enemy, "assets/squirtle.png")

dirx = random.randint(1, 10)
diry = random.randint(1, 10)

update_start = time.time()
while ARPGMaker.isOpen():
    ARPGMaker.systemEventHandler()
    main_start = time.time()
    while (time.time() - main_start) < (1 / 60):
        update_delta = time.time() - update_start
        update_start = time.time()

        if enemy is not None:
            ARPGMaker.renderEntity(enemy)
            # ARPGMaker.movef(enemy, int(100 * update_delta * 100), 100, int(100 * update_delta * 100), 100)
            if ARPGMaker.getEntityPositionX(enemy) < 0 or ARPGMaker.getEntityPositionX(enemy) > width - 200:
                dirx = -dirx
                ARPGMaker.move(enemy, dirx, diry)
            elif ARPGMaker.getEntityPositionY(enemy) > height - 200 or ARPGMaker.getEntityPositionY(enemy) < 0:
                diry = -diry
                ARPGMaker.move(enemy, dirx, diry)
            else:
                ARPGMaker.move(enemy, dirx, diry)

        # Handle input and boundaries
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

        if enemy is not None and attack is not None and ARPGMaker.circleCollide(attack, enemy):
            ARPGMaker.remEntity(enemy)
            enemy = None

        # if enemy is not None and ARPGMaker.circleCollide(player, enemy):
        #     ARPGMaker.close()

        # Draw everything
        draw.draw_all()
        if attack is not None:
            ARPGMaker.renderEntity(attack)
            ARPGMaker.remEntity(attack)
            attack = None                

ARPGMaker.close()

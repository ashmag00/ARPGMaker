import ARPGMaker
import time
import random

import draw

class Enemy:
    def __init__(self, id, dx, dy):
        self.id = id
        self.dx = dx
        self.dy = dy

width = 1000
height = 600
tile_size = 128
ARPGMaker.init(width, height, tile_size, "Noah's Hack 'n Slash")

ARPGMaker.loadTexture("assets/player.png")
# ARPGMaker.loadTexture("assets/player-1.png")
# ARPGMaker.loadTexture("assets/player-2.png")
# ARPGMaker.loadTexture("assets/player-3.png")
ARPGMaker.loadTexture("assets/sword.png")
# ARPGMaker.loadTexture("assets/sword-1.png")
# ARPGMaker.loadTexture("assets/sword-2.png")
# ARPGMaker.loadTexture("assets/sword-3.png")
ARPGMaker.loadTexture("assets/enemy.png")
ARPGMaker.loadTexture("assets/metal.png")

ARPGMaker.setBackground("assets/metal.png")

player_radius = 32
player = ARPGMaker.createEntity(int(width / 2), int(height / 2), player_radius)
ARPGMaker.setTexture(player, "assets/player.png")
attack = None

enemy_radius = 32

spawn_time = None
enemy_list = []
enemy_kills = 0

update_start = time.time()
while ARPGMaker.isOpen():
    ARPGMaker.systemEventHandler()
    main_start = time.time()

    if spawn_time is None or time.time() - spawn_time > 1:
        spawn_time = time.time()
        dirx = random.randint(15, 300)
        diry = random.randint(15, 300)
        e1 = Enemy(ARPGMaker.createEntity(random.randint(0, width - enemy_radius), random.randint(0, enemy_radius), enemy_radius), dirx, diry)
        ARPGMaker.setTexture(e1.id, "assets/enemy.png")
        enemy_list.append(e1)

    while (time.time() - main_start) < (1 / 60):
        update_delta = time.time() - update_start
        update_start = time.time()

        for enemy in enemy_list:
            if enemy is not None:
                ARPGMaker.renderEntity(enemy.id)
                if ARPGMaker.getEntityPositionX(enemy.id) < 0 or ARPGMaker.getEntityPositionX(enemy.id) > width - enemy_radius:
                    enemy.dx = -enemy.dx
                elif ARPGMaker.getEntityPositionY(enemy.id) > height - enemy_radius or ARPGMaker.getEntityPositionY(enemy.id) < 0:
                    enemy.dy= -enemy.dy
                
                ARPGMaker.movef(enemy.id, int(enemy.dx * update_delta * 100), 100, int(enemy.dy * update_delta * 100), 100)

        # Handle input and boundaries
        # d = ''
        if ARPGMaker.isKeyPressed('W') == 1 and ARPGMaker.getEntityPositionY(player) > 0:
            # d = 'W'
            # ARPGMaker.setTexture(player, "assets/player.png")
            ARPGMaker.movef(player, 0, 1, int(-500 * update_delta * 100), 100)
        if ARPGMaker.isKeyPressed('S') == 1 and ARPGMaker.getEntityPositionY(player) < height - player_radius:
            # d = 'S'
            # ARPGMaker.setTexture(player, "assets/player-2.png")
            ARPGMaker.movef(player, 0, 1, int(500 * update_delta * 100), 100)
        if ARPGMaker.isKeyPressed('A') == 1 and ARPGMaker.getEntityPositionX(player) > 0:
            # d = 'A'
            # ARPGMaker.setTexture(player, "assets/player-3.png")
            ARPGMaker.movef(player, int(-500 * update_delta * 100), 100, 0, 1)
        if ARPGMaker.isKeyPressed('D') == 1 and ARPGMaker.getEntityPositionX(player) < width - player_radius:
            # d = 'D'
            # ARPGMaker.setTexture(player, "assets/player-1.png")
            ARPGMaker.movef(player, int(500 * update_delta * 100), 100, 0, 1)

        # tmp = None
        if ARPGMaker.mouseLeftClick():
            # if d == 'W':
            attack = ARPGMaker.createEntity(ARPGMaker.getEntityPositionX(player) + 45, ARPGMaker.getEntityPositionY(player), 30)
            ARPGMaker.setTexture(attack, "assets/sword.png")
                # tmp = "assets/sword.png"
            # elif d == 'S':
            #     attack = ARPGMaker.createEntity(ARPGMaker.getEntityPositionX(player) + 5, ARPGMaker.getEntityPositionY(player) + 25, 20)
            #     tmp = "assets/sword-2.png"
            # elif d == 'A':
            #     attack = ARPGMaker.createEntity(ARPGMaker.getEntityPositionX(player), ARPGMaker.getEntityPositionY(player), 20)
            #     tmp = "assets/sword-3.png"
            # elif d == 'D':
            #     attack = ARPGMaker.createEntity(ARPGMaker.getEntityPositionX(player) + 45, ARPGMaker.getEntityPositionY(player) + 45, 20)
            #     tmp = "assets/sword-1.png"
            
            # if tmp is None:
            #     attack = ARPGMaker.createEntity(ARPGMaker.getEntityPositionX(player) + 45, ARPGMaker.getEntityPositionY(player), 20)
            #     ARPGMaker.setTexture(attack, "assets/sword.png")
            # else:
            #     ARPGMaker.setTexture(attack, tmp)

        for enemy in enemy_list:
            if ARPGMaker.circleCollide(player, enemy.id):
                ARPGMaker.close()

            if attack is not None and ARPGMaker.circleCollide(attack, enemy.id):
                enemy_list.remove(enemy)
                ARPGMaker.remEntity(enemy.id)
                enemy_kills += 1

        # Draw everything
        draw.draw_all()
        if attack is not None:
            ARPGMaker.remEntity(attack)
            attack = None

if enemy_kills == 1:
    print("You killed", enemy_kills, "enemy")
else:
    print("You killed", enemy_kills, "enemies")

ARPGMaker.close()

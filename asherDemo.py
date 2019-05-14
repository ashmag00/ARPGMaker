import ARPGMaker
import time
import random

import draw

width = 1200
height = 800
tile_size = 128
bulletList = []
enemyBulletList = []
ARPGMaker.init(width, height, tile_size, "Asher's Demo")

ARPGMaker.loadTexture("assets/pikachu.png")
ARPGMaker.loadTexture("assets/squirtle.png")
ARPGMaker.loadTexture("assets/tileBack.png")
ARPGMaker.loadTexture("assets/orb.png")
ARPGMaker.setBackground("assets/tileBack.png")

player_radius = 64
player_health = 3
player = ARPGMaker.createEntity(int(width / 2), int(height / 2), player_radius)
ARPGMaker.setTexture(player, "assets/pikachu.png")
attack = None

enemy_radius = 100
enemydx = 500
enemy_health = 50
enemy = ARPGMaker.createEntity(0, 0, enemy_radius)
ARPGMaker.setTexture(enemy, "assets/squirtle.png")

update_start = time.time()
fire_time = None
enemy_fire_time = None
#Game loop
while ARPGMaker.isOpen():
    ARPGMaker.systemEventHandler()
    main_start = time.time()
    #Handle firerate
    if ARPGMaker.mouseLeftClick() and (fire_time is None or time.time() - fire_time > (1/15)):
        fire_time = time.time()
        attack = ARPGMaker.createEntity(ARPGMaker.getEntityPositionX(player),\
         ARPGMaker.getEntityPositionY(player) - player_radius, 64)
        ARPGMaker.setTexture(attack, "assets/orb.png")
        bulletList.append(attack)
    if enemy is not None and (enemy_fire_time is None or (time.time() - enemy_fire_time) > (1/20)):
        enemy_fire_time = time.time()
        attack = ARPGMaker.createEntity(ARPGMaker.getEntityPositionX(enemy),\
         ARPGMaker.getEntityPositionY(enemy) + enemy_radius, 64)
        ARPGMaker.setTexture(attack, "assets/orb.png")
        enemyBulletList.append(attack)
    #Time mangement
    while (time.time() - main_start) < (1 / 60):
        update_delta = time.time() - update_start
        update_start = time.time()

        # Handle input and boundaries
        if ARPGMaker.isKeyPressed('W') == 1 and ARPGMaker.getEntityPositionY(player) > 0:
            ARPGMaker.movef(player, 0, 1, int(-500 * update_delta * 100), 100)
        if ARPGMaker.isKeyPressed('S') == 1 and ARPGMaker.getEntityPositionY(player) \
         < height - player_radius*2:
            ARPGMaker.movef(player, 0, 1, int(500 * update_delta * 100), 100)
        if ARPGMaker.isKeyPressed('A') == 1 and ARPGMaker.getEntityPositionX(player) > 0:
            ARPGMaker.movef(player, int(-500 * update_delta * 100), 100, 0, 1)
        if ARPGMaker.isKeyPressed('D') == 1 and ARPGMaker.getEntityPositionX(player) \
         < width - player_radius*2:
            ARPGMaker.movef(player, int(500 * update_delta * 100), 100, 0, 1)
        if enemy is not None:
            if ARPGMaker.getEntityPositionX(enemy)+enemy_radius*2 >= width or \
             ARPGMaker.getEntityPositionX(enemy) < 0:
                enemydx = -enemydx
            ARPGMaker.movef(enemy, int(enemydx * update_delta * 100), 100, 0, 1)

        #Bullet madness
        for bullet in bulletList:
            if ARPGMaker.getEntityPositionY(bullet) < 0 - 128:
                bulletList.remove(bullet)
                ARPGMaker.remEntity(bullet)
            elif enemy is not None and ARPGMaker.circleCollide(enemy, bullet):
                bulletList.remove(bullet)
                ARPGMaker.remEntity(bullet)
                enemy_health-=1
                if enemy_health <= 0:
                    print("YOU DID A WIN")
                    print("Remaining health: " + str(player_health))
                    ARPGMaker.close()
                    ARPGMaker.remEntity(enemy)
                    enemy = None
            else:
                ARPGMaker.movef(bullet, 0, 1, int(-500 * update_delta * 100), 100)
                for enBullet in enemyBulletList:
                    if ARPGMaker.circleCollide(enBullet, bullet):
                        bulletList.remove(bullet)
                        ARPGMaker.remEntity(bullet)
                        enemyBulletList.remove(enBullet)
                        ARPGMaker.remEntity(enBullet)
                        break


        for bullet in enemyBulletList:
            if ARPGMaker.getEntityPositionY(bullet) > height:
                enemyBulletList.remove(bullet)
                ARPGMaker.remEntity(bullet)
            elif ARPGMaker.circleCollide(player, bullet):
                #FIXME: MAKE A DEATH
                player_health-=1
                print("YOU DID A HIT")
                enemyBulletList.remove(bullet)
                ARPGMaker.remEntity(bullet)
                if player_health <= 0:
                    print("YOU DID A DEATH")
                    ARPGMaker.close()
            else:
                ARPGMaker.movef(bullet, 0, 1, int(500 * update_delta * 100), 100)


        # if enemy is not None and ARPGMaker.circleCollide(player, enemy):
        #     ARPGMaker.close()

        # Draw everything
        draw.draw_all()
        # if attack is not None:
        #    ARPGMaker.remEntity(attack)
        #    attack = None                

ARPGMaker.close()

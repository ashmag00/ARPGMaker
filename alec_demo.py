import ARPGMaker
import time
import alec_demo_assets, alec_demo_entities, alec_demo_draw

# Start the engine
ARPGMaker.init(800, 600, 32, "Alec's ARPGMaker Demo")

#Create all entities
alec_demo_entities.entity("Pikachu", 0, 0, 50, "assets/pikachu.png")
alec_demo_entities.entity("Squirtle", 400, 200, 50, "assets/squirtle.png")

#Main Lewp



update_start = time.time()
while ARPGMaker.isOpen():
    ARPGMaker.systemEventHandler()
    main_start = time.time()
    while (time.time() - main_start) < (1 / 60):
        update_delta = time.time() - update_start
        update_start = time.time()

    alec_demo_draw.draw_all()

ARPGMaker.close()
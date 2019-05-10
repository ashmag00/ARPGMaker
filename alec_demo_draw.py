import ARPGMaker
import alec_demo_assets, alec_demo_entities

# Create texture objects
alec_demo_assets.texture("Pikachu", "assets/pikachu.png")
alec_demo_assets.texture("Squirtle", "assets/squirtle.png")

for every_texture in alec_demo_assets.get_list_of_textures():
    ARPGMaker.loadTexture(every_texture.get_filepath())
    print("HERE")

def draw_all():
    ARPGMaker.clear()
    ARPGMaker.renderImage("assets/testBack.png")
    # for every_entity in alec_demo_entities.get_list_of_entities():
    #     ARPGMaker.renderEntity(every_entity.get_arpgmid())
    ARPGMaker.renderEntities()
    ARPGMaker.draw()
    ARPGMaker.display()
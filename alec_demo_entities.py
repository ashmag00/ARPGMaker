import ARPGMaker

list_of_entities = []

def get_list_of_entities():
    return list_of_entities

class entity():
    
    def __init__(self, name, posX, posY, collision_radius, texture_path):
        self.name = name
        self.pos = (posX, posY)
        self.collision_radius = collision_radius
        self.texture = texture_path
        self.arpgmid = ARPGMaker.createEntity(posX, posY, collision_radius)
        ARPGMaker.setTexture(self.arpgmid, texture_path)
        print(self.arpgmid, self.texture)
        list_of_entities.append(self)
        
    def get_arpgmid(self):
        return self.arpgmid

import ARPGMaker

list_of_textures = []

def get_list_of_textures():
    return list_of_textures

class texture():
    
    def __init__(self, name, texture_path):
        self.name = name
        self.filepath = texture_path
        list_of_textures.append(self)
        
    def get_filepath(self):
        # print(self.filepath)
        return self.filepath
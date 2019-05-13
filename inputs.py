import ARPGMaker

def process_inputs(update_delta):
    if ARPGMaker.isKeyPressed('W') == 1 and ARPGMaker.getEntityPositionY(player) > 0:
        ARPGMaker.movef(player, 0, 1, int(-1000 * update_delta * 100), 100)
    if ARPGMaker.isKeyPressed('S') == 1 and ARPGMaker.getEntityPositionY(player) < height - player_radius:
        ARPGMaker.movef(player, 0, 1, int(1000 * update_delta * 100), 100)
    if ARPGMaker.isKeyPressed('A') == 1 and ARPGMaker.getEntityPositionX(player) > 0:
        ARPGMaker.movef(player, int(-1000 * update_delta * 100), 100, 0, 1)
    if ARPGMaker.isKeyPressed('D') == 1 and ARPGMaker.getEntityPositionX(player) < width - player_radius:
        ARPGMaker.movef(player, int(1000 * update_delta * 100), 100, 0, 1)
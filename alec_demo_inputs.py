import ARPGMaker

if ARPGMaker.isKeyPressed('W') == 1:
        ARPGMaker.movef(player1_ID, 0, 1, int(-1500 * update_delta * 100), 100)
    if ARPGMaker.isKeyPressed('S') == 1:
        ARPGMaker.movef(player1_ID, 0, 1, int(1500 * update_delta * 100), 100)
    if ARPGMaker.isKeyPressed('A') == 1:
        ARPGMaker.movef(player1_ID, int(-1500 * update_delta * 100), 100, 0, 1)
    if ARPGMaker.isKeyPressed('D') == 1:
        ARPGMaker.movef(player1_ID, int(1500 * update_delta * 100), 100, 0, 1)
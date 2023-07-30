#include "game.h"

Game::Game()
{
    grid = Grid();
    blocks = {LBlock(), JBlock(), TBlock(), ZBlock(), SBlock(), OBlock(), IBlock()};
}
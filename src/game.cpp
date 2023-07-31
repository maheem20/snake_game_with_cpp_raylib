#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = {LBlock(), JBlock(), TBlock(), ZBlock(), SBlock(), OBlock(), IBlock()};
}

Block Game::GetRandomBlock()
{
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
}
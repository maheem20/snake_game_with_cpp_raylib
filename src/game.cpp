#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {LBlock(), JBlock(), TBlock(), ZBlock(), SBlock(), OBlock(), IBlock()};
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput(){
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
        case KEY_LEFT:
        break;
    }
}

void Game::MoveBlockLeft(){
    currentBlock.Move(0, -1);
}
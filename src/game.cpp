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

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
    if (isBlockOutside())
    {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);
    if (isBlockOutside())
    {
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
    if (isBlockOutside())
    {
        currentBlock.Move(-1, 0);
        lockBlock();
    }
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
    if (isBlockOutside())
    {
        currentBlock.UndoRotation();
    }
}

void Game::lockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
}

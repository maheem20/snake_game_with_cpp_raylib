#pragma once
#include <grid.h>
#include <blocks.cpp>

class Game
{
public:
    Game();
    Block GetRandomBlock();
    Grid grid;

private:
    std::vector<Block> blocks;
};
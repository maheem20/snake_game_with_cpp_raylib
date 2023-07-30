#pragma once

class Game
{
public:
    Game();
    Grid grid;

private:
    std::vector<Block> blocks;
};
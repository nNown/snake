#pragma once

#include <array>
#include <iostream>
#include <player.h>
#include <vector>

class BoardEntity {
    private:
        std::array<unsigned int, 2> dimensions;
        std::vector<std::vector<char>> board;
        PlayerEntity player;

    public:
        void PrintBoard();

        BoardEntity(const std::array<unsigned int, 2>& dimensions, const PlayerEntity& player);
        ~BoardEntity();
};
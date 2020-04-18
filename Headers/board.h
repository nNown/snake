#pragma once

#include <array>
#include <iostream>
#include <player.h>
#include <vector>

class BoardEntity {
    private:
        std::array<unsigned int, 2> _dimensions;
        std::vector<std::vector<char>> board;
        PlayerEntity player;

    public:
        std::array<unsigned int, 2> Dimensions() const;

        void PrintBoard();

        BoardEntity(const std::array<unsigned int, 2>& dimensions, const PlayerEntity& player);
        ~BoardEntity();
};
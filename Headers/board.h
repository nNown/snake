#pragma once

#include <array>
#include <iostream>
#include <player.h>
#include <vector>

class BoardEntity {
    private:
        std::array<unsigned int, 2> _dimensions;
        std::vector<std::vector<char>> board;
        PlayerEntity _player;

    public:
        std::array<unsigned int, 2> Dimensions() const;
        PlayerEntity* Player();

        void Draw();

        BoardEntity(const std::array<unsigned int, 2>& dimensions, const PlayerEntity& player);
        ~BoardEntity();
};
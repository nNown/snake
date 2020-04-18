#pragma once

#include <array>
#include <iostream>
#include <player.h>
#include <food.h>
#include <vector>

class BoardEntity {
    private:
        std::array<unsigned int, 2> _dimensions;
        std::vector<std::vector<char>> _board;
        PlayerEntity _player;
        FoodEntity _food;

    public:
        std::array<unsigned int, 2> Dimensions() const;
        PlayerEntity* Player();
        FoodEntity* Food();

        void Draw();

        BoardEntity(const std::array<unsigned int, 2>& dimensions, const PlayerEntity& player, const FoodEntity& food);
        ~BoardEntity();
};
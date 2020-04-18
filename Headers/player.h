#pragma once

#include <iostream>
#include <vector>
#include <array>

class PlayerEntity {
    private:
        char _body;
        std::vector<std::array<unsigned int, 2>> _bodyPartsPositions;
        std::array<int, 2> direction;

    public:
        char Body();
        std::vector<std::array<unsigned int, 2>> BodyPartsPositions();

        PlayerEntity();
        PlayerEntity(const char& body, const std::array<unsigned int, 2>& startingPosition);
        PlayerEntity(const PlayerEntity& player);
        ~PlayerEntity();
};
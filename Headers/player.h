#pragma once

#include <array>
#include <iostream>
#include <vector>

class PlayerEntity {
    private:
        char _body;
        std::vector<std::array<unsigned int, 2>> _bodyPartsPositions;
        std::array<int, 2> _direction;

    public:
        char Body() const;
        std::vector<std::array<unsigned int, 2>> BodyPartsPositions() const;
        std::array<int, 2> Direction() const;

        void AddBodyPart(std::array<unsigned int, 2> dimensions);
        void SetNextState();

        PlayerEntity();
        PlayerEntity(const char& body, const std::array<unsigned int, 2>& startingPosition);
        PlayerEntity(const PlayerEntity& player);
        ~PlayerEntity();
};
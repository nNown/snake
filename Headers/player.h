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
        void SetDirection(const std::array<int, 2>& newDirection);

        void AddBodyPart(const std::array<unsigned int, 2>& dimensions);
        void MovePlayer(const std::array<unsigned int, 2>& dimensions);

        PlayerEntity();
        PlayerEntity(const char& body, const std::array<unsigned int, 2>& startingPosition);
        PlayerEntity(const PlayerEntity& player);
        ~PlayerEntity();
};
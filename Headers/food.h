#pragma once 

#include <array>
#include <iostream>

class FoodEntity {
    private:
        char _body;
        std::array<unsigned int, 2> _position;
    
    public:
        char Body() const;
        std::array<unsigned int, 2> Position() const;
        void SetPosition(std::array<unsigned int, 2> newPosition);

        FoodEntity();
        FoodEntity(const std::array<unsigned int, 2>& position);
        FoodEntity(const char& body, const std::array<unsigned int, 2>& position);
        FoodEntity(const FoodEntity& food);
        ~FoodEntity();
};
#pragma once 

#include <array>

class FoodEntity {
    private:
        char _body;
        std::array<unsigned int, 2> _position;
    
    public:
        char Body() const;
        std::array<unsigned int, 2> Position() const;

        FoodEntity();
        FoodEntity(const char* body, const std::array<unsigned int, 2>* position);
        FoodEntity(const FoodEntity* food);
        ~FoodEntity();
};
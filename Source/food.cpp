#include <food.h>

char FoodEntity::Body() const { return this->_body; }
std::array<unsigned int, 2> FoodEntity::Position() const { return this->_position; }
void FoodEntity::SetPosition(const std::array<unsigned int, 2>& newPosition) { this->_position = newPosition; }

FoodEntity::FoodEntity()
    : _body('O'), _position({ 1, 1 }) {}

FoodEntity::FoodEntity(const std::array<unsigned int, 2>& position) 
    : _body('O'), _position(position) {}

FoodEntity::FoodEntity(const char& body, const std::array<unsigned int, 2>& position) 
    : _body(body), _position(position) {}

FoodEntity::FoodEntity(const FoodEntity& food) 
    : _body(food._body), _position(food._position) {}

FoodEntity::~FoodEntity() {
    std::cout << "Food destroyed" << std::endl;
}
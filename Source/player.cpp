#include <player.h>

char PlayerEntity::Body() { return this->_body; }
std::vector<std::array<unsigned int, 2>> PlayerEntity::BodyPartsPositions() { return this->_bodyPartsPositions; }

PlayerEntity::PlayerEntity() 
    : _body('X'), _bodyPartsPositions(std::vector<std::array<unsigned int, 2>>(1, { 0, 0 })), direction(std::array<int, 2>({ 0, 0 })) { }

PlayerEntity::PlayerEntity(const char& body, const std::array<unsigned int, 2>& startingPosition) 
    : _body(body), _bodyPartsPositions(std::vector<std::array<unsigned int, 2>>(1, startingPosition)), direction(std::array<int, 2>({ 0, 0 })) { }

PlayerEntity::PlayerEntity(const PlayerEntity& player) 
    : _body(player._body), _bodyPartsPositions(std::vector<std::array<unsigned int, 2>>(player._bodyPartsPositions)), direction(std::array<int, 2>(player.direction)) { }

PlayerEntity::~PlayerEntity() {
    std::cout << "Player destroyed" << std::endl;
}
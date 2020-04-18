#include <player.h>

char PlayerEntity::Body() const { return this->_body; }
std::vector<std::array<unsigned int, 2>> PlayerEntity::BodyPartsPositions() const { return this->_bodyPartsPositions; }
std::array<int, 2> PlayerEntity::Direction() const { return this->_direction; }

void PlayerEntity::AddBodyPart(std::array<unsigned int, 2> dimensions) {
    std::array<unsigned int, 2> lastBodyPart = this->_bodyPartsPositions[_bodyPartsPositions.size() - 1];

    if(lastBodyPart[0] == 0 && this->_direction[0] == 1) { lastBodyPart[0] = dimensions[0] - 1; }
    else if(lastBodyPart[0] == dimensions[0] - 1 && this->_direction[0] == -1) { lastBodyPart[0] = 0; }
    else if(lastBodyPart[1] == 0 && this->_direction[1] == 1) { lastBodyPart[1] = dimensions[1] - 1; }
    else if(lastBodyPart[1] == dimensions[1] - 1 && this->_direction[1] == -1) { lastBodyPart[1] = 0; }
    else {
        lastBodyPart[0] -= this->_direction[0];
        lastBodyPart[1] -= this->_direction[1];
    }

    _bodyPartsPositions.push_back(lastBodyPart);
}

void PlayerEntity::SetNextState() {
    
}

PlayerEntity::PlayerEntity() 
    : _body('X'), _bodyPartsPositions(std::vector<std::array<unsigned int, 2>>(1, { 0, 0 })), _direction(std::array<int, 2>({ 0, 0 })) { }

PlayerEntity::PlayerEntity(const char& body, const std::array<unsigned int, 2>& startingPosition) 
    : _body(body), _bodyPartsPositions(std::vector<std::array<unsigned int, 2>>(1, startingPosition)), _direction(std::array<int, 2>({ 0, 0 })) { }

PlayerEntity::PlayerEntity(const PlayerEntity& player) 
    : _body(player._body), _bodyPartsPositions(std::vector<std::array<unsigned int, 2>>(player._bodyPartsPositions)), _direction(std::array<int, 2>(player._direction)) { }

PlayerEntity::~PlayerEntity() {
    std::cout << "Player destroyed" << std::endl;
}
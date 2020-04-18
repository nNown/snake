#include <board.h>

std::array<unsigned int, 2> BoardEntity::Dimensions() const { return this->_dimensions; }

void BoardEntity::PrintBoard() {
    for(unsigned int i = 0; i < this->_dimensions[0]; i++) {
        for(unsigned int j = 0; j < this->_dimensions[1]; j++) {
            try {
                for(unsigned int k = 0; k < this->player.BodyPartsPositions().size(); k++) {
                    if(i == this->player.BodyPartsPositions()[k][0] && j == this->player.BodyPartsPositions()[k][1]) this->board[i][j] = this->player.Body();
                }
                std::cout << this->board[i][j];
            } catch(const std::out_of_range& ex) {
                std::cout << "Out of range exception caught:: " << ex.what() << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

BoardEntity::BoardEntity(const std::array<unsigned int, 2>& _dimensions, const PlayerEntity& player) {
    this->player = PlayerEntity(player);
    this->_dimensions = std::array<unsigned int, 2>(_dimensions);
    this->board = std::vector<std::vector<char>>(this->_dimensions[0], std::vector<char>(this->_dimensions[1], 0));
    for(unsigned int i = 0; i < this->_dimensions[0]; i++) {
        for(unsigned int j = 0; j < this->_dimensions[1]; j++) {
            try {
                if(i == 0 || i == this->_dimensions[0] - 1) this->board[i][j] = '-';
                else if(j == 0 || j == this->_dimensions[1] - 1) this->board[i][j] = '|';
            } catch(const std::out_of_range& ex) {
                std::cout << "Out of range exception caught:: " << ex.what() << std::endl;
            }
        }
    }
}

BoardEntity::~BoardEntity() {
    std::cout << "Board destroyed" << std::endl;
}
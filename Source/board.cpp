#include <board.h>

void BoardEntity::PrintBoard() {
    for(unsigned int i = 0; i < this->dimensions[0]; i++) {
        for(unsigned int j = 0; j < this->dimensions[1]; j++) {
            try {
                std::cout << this->board[i][j];
            } catch(const std::out_of_range& ex) {
                std::cout << "Out of range exception caught:: " << ex.what() << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

BoardEntity::BoardEntity(const std::array<unsigned int, 2>& dimensions, const PlayerEntity& player) {
    this->player = PlayerEntity(player);
    this->dimensions = std::array<unsigned int, 2>(dimensions);
    this->board = std::vector<std::vector<char>>(this->dimensions[0], std::vector<char>(this->dimensions[1], 0));
    for(unsigned int i = 0; i < this->dimensions[0]; i++) {
        for(unsigned int j = 0; j < this->dimensions[1]; j++) {
            try {
                if(i == 0 || i == this->dimensions[0] - 1) this->board[i][j] = '-';
                else if(j == 0 || j == this->dimensions[1] - 1) this->board[i][j] = '|';
                else if(i == this->player.BodyPartsPositions()[0][0] && j == this->player.BodyPartsPositions()[0][1]) this->board[i][j] = this->player.Body();
            } catch(const std::out_of_range& ex) {
                std::cout << "Out of range exception caught:: " << ex.what() << std::endl;
            }
        }
    }
}

BoardEntity::~BoardEntity() {
    std::cout << "Board destroyed" << std::endl;
}
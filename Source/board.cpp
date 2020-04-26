#include <board.h>

std::array<unsigned int, 2> BoardEntity::Dimensions() const { return this->_dimensions; }
PlayerEntity* BoardEntity::Player() { return &(this->_player); }
FoodEntity* BoardEntity::Food() { return &(this->_food); }

void BoardEntity::Draw() {
    for(unsigned int i = 0; i < this->_dimensions[0]; i++) {
        for(unsigned int j = 0; j < this->_dimensions[1]; j++) {
            try {
                if(i == 0 || i == this->_dimensions[0] - 1) this->_board[i][j] = '-';
                else if(j == 0 || j == this->_dimensions[1] - 1) this->_board[i][j] = '|';
                else if(i == this->_food.Position()[0] && j == this->_food.Position()[1]) this->_board[i][j] = this->_food.Body();
                else this->_board[i][j] = 0;
                for(unsigned int k = 0; k < this->_player.BodyPartsPositions().size(); k++) {
                    if(i == this->_player.BodyPartsPositions()[k][0] && j == this->_player.BodyPartsPositions()[k][1]) this->_board[i][j] = this->_player.Body();
                }
                std::cout << this->_board[i][j];
            } catch(const std::out_of_range& ex) {
                std::cout << "Out of range exception caught:: " << ex.what() << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

void BoardEntity::ManageFood() {
    if(this->_player.BodyPartsPositions()[0][0] == this->_food.Position()[0] && this->_player.BodyPartsPositions()[0][1] == this->_food.Position()[1]) {
        this->_player.AddBodyPart(this->_dimensions);
        this->_food.SetPosition({1 + rand() % (this->_dimensions[0] - 2), 1 + rand() % (this->_dimensions[1] - 2)});
    }
}

BoardEntity::BoardEntity(const std::array<unsigned int, 2>& _dimensions, const PlayerEntity& player, const FoodEntity& food) {
    this->_dimensions = std::array<unsigned int, 2>(_dimensions);
    this->_board = std::vector<std::vector<char>>(this->_dimensions[0], std::vector<char>(this->_dimensions[1], 0));
    this->_player = PlayerEntity(player);
    this->_food = FoodEntity(food);
}

BoardEntity::~BoardEntity() {
    std::cout << "_board destroyed" << std::endl;
}
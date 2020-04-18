#include <array>
#include <board.h>
#include <cstdlib>
#include <ctime>
#include <player.h>
#include <food.h>
#include <vector>
#include <windows.h>

// VK_LEFT   A 
// 0x25      0x41

// VK_UP     W
// 0x26      0x57

// VK_RIGHT  D
// 0x27      0x44

// VK_DOWN   S
// 0x28      0x53

#define PressedKeyMask 0x8000

void GetInput(PlayerEntity* player);
void ManageFood(BoardEntity& board);

int main() {
    std::srand(std::time(nullptr));
    std::array<unsigned int, 2> dimensions = { 10, 25 };
    BoardEntity board = BoardEntity(dimensions, PlayerEntity('X', { 6, 15 }), FoodEntity({1 + rand() % (dimensions[0] - 2), 1 + rand() % (dimensions[1] - 2)}));


    while(!board.Player()->GameState()) {
        GetInput(board.Player());
        board.Player()->MovePlayer(board.Dimensions());
        ManageFood(board);
        board.Draw();
        Sleep(125);
        std::system("cls");
        std::cout << board.Food()->Position()[0] << ";" << board.Food()->Position()[1] << std::endl;
    }

    std::exit(0);
}

void GetInput(PlayerEntity* player) {
    if(GetKeyState(VK_LEFT) & PressedKeyMask || GetKeyState(0x41) & PressedKeyMask) player->SetDirection({ 0, -1 });
    else if(GetKeyState(VK_UP) & PressedKeyMask || GetKeyState(0x57) & PressedKeyMask) player->SetDirection({ -1, 0 });
    else if(GetKeyState(VK_RIGHT) & PressedKeyMask || GetKeyState(0x44) & PressedKeyMask) player->SetDirection({ 0, 1 });
    else if(GetKeyState(VK_DOWN) & PressedKeyMask || GetKeyState(0x53) & PressedKeyMask) player->SetDirection({ 1, 0 });
    else if(GetKeyState(VK_ESCAPE) & PressedKeyMask) player->SetGameState(true);
}

void ManageFood(BoardEntity& board) {
    if(board.Player()->BodyPartsPositions()[0][0] == board.Food()->Position()[0] && board.Player()->BodyPartsPositions()[0][1] == board.Food()->Position()[1]) {
        board.Player()->AddBodyPart(board.Dimensions());
        board.Food()->SetPosition({1 + rand() % (board.Dimensions()[0] - 2), 1 + rand() % (board.Dimensions()[1] - 2)});
    }
}

#include <array>
#include <board.h>
#include <player.h>
#include <vector>
#include <windows.h>

#define PressedKeyMask 0x8000

int main() {
    BoardEntity board = BoardEntity({ 10, 25 }, PlayerEntity('X', { 5, 5 }));
    board.Player()->SetDirection({ 0, 1 });

    while(!(GetKeyState(VK_ESCAPE) & PressedKeyMask)) {
        board.Draw();
        board.Player()->MovePlayer(board.Dimensions());
        Sleep(125);
        std::system("cls");
        std::cout << board.Player()->BodyPartsPositions()[0][0] << std::endl << board.Player()->BodyPartsPositions()[0][1] << std::endl;
    }

    std::exit(0);
}
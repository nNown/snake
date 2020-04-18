#include <array>
#include <board.h>
#include <player.h>
#include <vector>
#include <windows.h>

#define PressedKeyMask 0x8000

int main() {
    BoardEntity board = BoardEntity({ 10, 25 }, PlayerEntity('X', { 5, 5 }));

    while(!(GetKeyState(VK_ESCAPE) & PressedKeyMask)) {
        board.PrintBoard();
        std::system("cls");
    }

    std::exit(0);
}
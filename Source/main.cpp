#include <array>
#include <board.h>
#include <player.h>
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

int main() {
    BoardEntity board = BoardEntity({ 10, 25 }, PlayerEntity('X', { 6, 15 }));
    board.Player()->SetDirection({-1, 0});
    board.Player()->AddBodyPart(board.Dimensions());
    board.Player()->AddBodyPart(board.Dimensions());
    board.Player()->AddBodyPart(board.Dimensions());
    board.Player()->AddBodyPart(board.Dimensions());
    board.Player()->AddBodyPart(board.Dimensions());

    while(!(GetKeyState(VK_ESCAPE) & PressedKeyMask) && !board.Player()->GameState()) {
        GetInput(board.Player());
        board.Player()->MovePlayer(board.Dimensions());
        board.Draw();
        Sleep(250);
        std::system("cls");
    }

    std::exit(0);
}

void GetInput(PlayerEntity* player) {
    if(GetKeyState(VK_LEFT) & PressedKeyMask || GetKeyState(0x41) & PressedKeyMask) player->SetDirection({ 0, -1 });
    else if(GetKeyState(VK_UP) & PressedKeyMask || GetKeyState(0x57) & PressedKeyMask) player->SetDirection({ -1, 0 });
    else if(GetKeyState(VK_RIGHT) & PressedKeyMask || GetKeyState(0x44) & PressedKeyMask) player->SetDirection({ 0, 1 });
    else if(GetKeyState(VK_DOWN) & PressedKeyMask || GetKeyState(0x53) & PressedKeyMask) player->SetDirection({ 1, 0 });
}

#include <game.h>
#include <windows.h>

void cls(GameEntity* gameEntity, BoardEntity* board);

int main() {
    GameEntity* gameEntity = GameEntity::GetGameEntityInstance({25, 40});

    // cls(gameEntity, gameEntity->Board());
    std::system("cls"); // TEMPORARY
    while(!gameEntity->GetGameState()) {
        gameEntity->GetInput();
        gameEntity->Draw();
        // Sleep(75);
        // std::system("cls");
        cls(gameEntity, gameEntity->Board());
    }

    std::exit(0);
}

void cls(GameEntity* gameEntity, BoardEntity* board) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { (SHORT)board->Dimensions()[0], (SHORT)board->Dimensions()[1] };

    if(!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        abort();
    }

    DWORD length = (board->Dimensions()[0] - 4) * (board->Dimensions()[1] - 4);
    DWORD written;

    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);
    
    SetConsoleCursorPosition(hOut, { 0, 0 });
    gameEntity->CursorState(false);
}
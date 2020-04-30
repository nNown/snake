#include <game.h>
#include <windows.h>

void cls(GameEntity* gameEntity, BoardEntity* board);

int main() {
    GameEntity* gameEntity = GameEntity::GetGameEntityInstance({25, 30});

    cls(gameEntity, gameEntity->Board());
    while(!gameEntity->GetGameState()) {
        gameEntity->GetInput();
        gameEntity->Draw();
        Sleep(75);
        // std::system("cls");
        cls(gameEntity, gameEntity->Board());
    }

    std::exit(0);
}

void cls(GameEntity* gameEntity, BoardEntity* board) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

    if(!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        abort();
    }

    DWORD length = (board->Dimensions()[0] - 2) * (board->Dimensions()[1] - 2);
    DWORD written;

    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);
    
    SetConsoleCursorPosition(hOut, topLeft);
    gameEntity->CursorState(false);
}
#include <game.h>

int main() {
    GameEntity* gameEntity = GameEntity::GetGameEntityInstance({25, 30});
    gameEntity->CursorState(false);

    while(!gameEntity->GetGameState()) {
        gameEntity->GetInput();
        gameEntity->Draw();
        Sleep(125);
        std::system("cls");
    }

    std::exit(0);
}
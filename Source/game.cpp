#include <game.h>

GameEntity* GameEntity::GameInstance = NULL;

void GameEntity::Draw() {
    this->board->Player()->MovePlayer(this->board->Dimensions());
    this->board->ManageFood();
    this->board->Draw();
}

void GameEntity::GetInput() {
    if(GetKeyState(VK_LEFT) & PressedKeyMask || GetKeyState(0x41) & PressedKeyMask) this->board->Player()->SetDirection({ 0, -1 });
    else if(GetKeyState(VK_UP) & PressedKeyMask || GetKeyState(0x57) & PressedKeyMask) this->board->Player()->SetDirection({ -1, 0 });
    else if(GetKeyState(VK_RIGHT) & PressedKeyMask || GetKeyState(0x44) & PressedKeyMask) this->board->Player()->SetDirection({ 0, 1 });
    else if(GetKeyState(VK_DOWN) & PressedKeyMask || GetKeyState(0x53) & PressedKeyMask) this->board->Player()->SetDirection({ 1, 0 });
    else if(GetKeyState(VK_ESCAPE) & PressedKeyMask) this->board->Player()->SetGameState(true);
}

void GameEntity::CursorState(bool state) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = state;
    SetConsoleCursorInfo(out, &cursorInfo);
}

bool GameEntity::GetGameState() { return this->board->Player()->GameState(); }

GameEntity::GameEntity(std::array<unsigned int, 2> dimensions) {
    std::srand(std::time(nullptr));
    this->board = new BoardEntity(dimensions, PlayerEntity('X', { 6, 15 }), FoodEntity({1 + rand() % (dimensions[0] - 2), 1 + rand() % (dimensions[1] - 2)}));
}

GameEntity* GameEntity::GetGameEntityInstance() {
    if(GameInstance == NULL) {
        return NULL;
    }

    return GameInstance;
}

GameEntity* GameEntity::GetGameEntityInstance(std::array<unsigned int, 2> dimensions) {
    if(GameInstance == NULL) {
        GameInstance = new GameEntity(dimensions);
    }

    return GameInstance;
}

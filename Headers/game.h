#pragma once

#include <array>
#include <board.h>
#include <ctime>
#include <cstdlib>
#include <food.h>
#include <player.h>
#include <windows.h>

#define PressedKeyMask 0x8000

class GameEntity {
    private: 
        static GameEntity* GameInstance;
        BoardEntity* board;
        GameEntity(std::array<unsigned int, 2> dimensions);

    public: 
        void Draw();
        void GetInput();
        void CursorState(bool state);
        bool GetGameState();

        static GameEntity* GetGameEntityInstance();
        static GameEntity* GetGameEntityInstance(std::array<unsigned int, 2> dimensions);
};
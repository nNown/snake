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
        GameEntity(const std::array<unsigned int, 2>& dimensions);

    public: 
        void Draw();
        void GetInput();
        void CursorState(const bool& state);
        bool GetGameState() const;

        BoardEntity* Board();

        static GameEntity* GetGameEntityInstance();
        static GameEntity* GetGameEntityInstance(const std::array<unsigned int, 2>& dimensions);
};
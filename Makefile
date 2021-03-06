GXX = g++
CPPFLAGS = -Wall -Wextra -Wno-unused-parameter
LDFLAGS = -I./Headers/
STDFLAG = -std=c++17
OPTIMALIZATION = -Ofast

all: debug

debug: Source/main.cpp Source/board.cpp Source/player.cpp Source/food.cpp Source/game.cpp
	$(GXX) $(CPPFLAGS) $(LDFLAGS) $(STDFLAG) -o main $^ $(OPTIMALIZATION)

GXX = g++
CPPFLAGS = -Wall -Wextra -Wno-unused-parameter
LDFLAGS = -I./Headers/
STDFLAG = -std=c++17
OPTIMALIZATION = -g -Og

all: debug

debug: Source/main.cpp Source/board.cpp Source/player.cpp
	$(GXX) $(CPPFLAGS) $(LDFLAGS) $(STDFLAG) -o main $^ $(OPTIMALIZATION)

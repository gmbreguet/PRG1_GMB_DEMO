MAIN    = 03_Moving_Point_SDL_MacOS.cpp
OTHERS  =
LIBRARY = -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2
OUTPUT  = 03_Moving_Point_SDL_MacOS.app

VERSION = -std=c++20
WARNING = -Wall -Wextra -Wconversion -Wsign-conversion -pedantic

all:
	g++ $(VERSION) $(LIBRARY) $(WARNING) $(OTHERS) $(MAIN) -o $(OUTPUT)
clean:
	rm main


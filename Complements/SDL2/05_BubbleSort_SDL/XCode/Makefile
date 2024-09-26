MAIN    = 05_BubbleSort_SDL_XCode.cpp
OTHERS  =
LIBRARY = -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2
OUTPUT  = 05_BubbleSort_SDL_XCode.out

VERSION = -std=c++20
WARNING = -Wall -Wextra -Wconversion -Wsign-conversion -pedantic

all:
	g++ $(VERSION) $(LIBRARY) $(WARNING) $(OTHERS) $(MAIN) -o $(OUTPUT)
clean:
	rm main


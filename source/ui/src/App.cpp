#include <iostream>

#include <SDL.h>

#include "App.h"

bool App::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << "\n";
		return false;
	}

    return true;
}

void App::run() {
    // todo
}
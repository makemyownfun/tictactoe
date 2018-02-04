#include <iostream>

#include <SDL.h>

#include "App.h"

bool App::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

    m_screenWidth = 1920;
    m_screenHeight = 1080;
	SDL_Window* window = SDL_CreateWindow("Tic Tac Toe", 
	                                    SDL_WINDOWPOS_UNDEFINED, 
										SDL_WINDOWPOS_UNDEFINED, 
										m_screenWidth, m_screenHeight, 
										SDL_WINDOW_RESIZABLE);

    if(window == nullptr) {
        std::cout << "window could not be created: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void App::run() {
    // todo
}
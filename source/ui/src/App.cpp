#include <iostream>

#include <SDL.h>

#include "App.h"

bool App::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

    m_screenWidth = 800;
    m_screenHeight = 450;
	SDL_Window* m_window = SDL_CreateWindow("Tic Tac Toe", 
	                                    SDL_WINDOWPOS_UNDEFINED, 
										SDL_WINDOWPOS_UNDEFINED, 
										m_screenWidth, m_screenHeight, 
										SDL_WINDOW_RESIZABLE);

    if(m_window == nullptr) {
        std::cout << "window could not be created: " << SDL_GetError() << std::endl;
        return false;
    }

	Uint32 flags = SDL_RENDERER_ACCELERATED;
	m_renderer = SDL_CreateRenderer(m_window, -1, flags);

    return true;
}

void App::run() {
    m_running = true;
    while(m_running) {
        handleEvents();
    }
}

void App::handleEvents() {
    SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			m_running = false;
		}
		else if (event.type == SDL_KEYUP) {
			if(event.key.keysym.sym == SDLK_ESCAPE) {
				m_running = false;
			}
		}
	}
}

void App::cleanup() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

	SDL_Quit();
}
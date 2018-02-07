#include <iostream>

#include <SDL.h>

#include "Screen.h"
#include "App.h"

bool App::init() {
	// initialize sdl2
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// setup the window
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

	// setup screen
	m_screen = new Screen();
	if(!m_screen->init(*m_window)) {
		std::cout << "screen failed to initialize\n";
		return false;
	}


    return true;
}

void App::run() {
    bool running = true;
    while(running) {
		// handle events
        running = m_screen->handleEvents();

		// update the screen
		m_screen->update();

		// display the screen
		m_screen->display();
    }
}

void App::cleanup() {
	m_screen->cleanup();
	delete(m_screen);
	m_screen = nullptr;

	SDL_DestroyWindow(m_window);

	SDL_Quit();
}
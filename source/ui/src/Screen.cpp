#include <SDL.h>

#include "Screen.h"

void Screen::init(int width, int height) {
    m_width = width;
    m_height = height;

    m_backgroundColor = {0xE0, 0xE0, 0xE0, 0x00};
}

// handles input events
// returns false if the app should quit
bool Screen::handleEvents() {
    SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			return false;
		}
		else if (event.type == SDL_KEYUP) {
			if(event.key.keysym.sym == SDLK_ESCAPE) {
				return false;
			}
		}
	}

    return true;
}

void Screen::update() {

}

void Screen::display(SDL_Renderer& renderer) {
    // clear the screen (with the current background color)
	SDL_SetRenderDrawColor(&renderer, 
        m_backgroundColor.r, 
        m_backgroundColor.g, 
        m_backgroundColor.b, 
        m_backgroundColor.a);
	SDL_RenderClear(&renderer);

    // render the screen
    
    

    // switch back and front buffer
    SDL_RenderPresent(&renderer);
}
#include <SDL.h>

#include "Screen.h"

void Screen::init(int width, int height) {
    m_width = width;
    m_height = height;
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
    // clear the screen
	SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, 0x00 );
	SDL_RenderClear(&renderer);

    // blit the screen to the renderer
    // render the background
    SDL_Rect fillRect = { m_width / 4, m_height / 4, m_width / 2, m_height / 2 };
    SDL_SetRenderDrawColor( &renderer, 0x00, 0x00, 0xFF, 0xFF );        
    SDL_RenderFillRect( &renderer, &fillRect );

    // switch back and front buffer
    SDL_RenderPresent(&renderer);
}
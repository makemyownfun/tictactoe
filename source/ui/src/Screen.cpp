#include <iostream>
#include <memory>

#include <SDL.h>

#include "Screen.h"

bool Screen::init(SDL_Window& window) {
    // setup the renderer
	Uint32 flags = SDL_RENDERER_ACCELERATED;
	m_renderer = SDL_CreateRenderer(&window, -1, flags);
	if(m_renderer == nullptr) {
        std::cout << "renderer could not be created: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_GetWindowSize(&window, &m_width, &m_height);

    m_backgroundColor = {0xE0, 0xE0, 0xE0, 0x00};

   	if(!loadTextures()) {
            std::cout << "failed to load all of the ui textures\n";
            return false;
    }

    return true;
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

void Screen::display() {
    // clear the screen (with the current background color)
	SDL_SetRenderDrawColor(m_renderer, 
        m_backgroundColor.r, 
        m_backgroundColor.g, 
        m_backgroundColor.b, 
        m_backgroundColor.a);
	SDL_RenderClear(m_renderer);

    // render the screen
    for(auto& element : m_children) {
        element->render(*m_renderer);
    }
    

    // switch back and front buffer
    SDL_RenderPresent(m_renderer);
}

// currently a hard coded list of textures
// TODO: load based on a text file that can be updadted without recompiling
bool Screen::loadTextures() {
    std::vector<std::string> names;
    names.push_back("button.bmp");
    names.push_back("button-hover.bmp");
    names.push_back("button-click.bmp");

    for(auto name : names) {
        m_textures[name] = std::unique_ptr<Texture>(new Texture());
        if(!m_textures[name]->loadTexture(*m_renderer, name)) {
            return false;
        }
    }

    return true;
}

void Screen::cleanup() {
    SDL_DestroyRenderer(m_renderer);
}
#include <SDL.h>

#include "Texture.h"

bool Texture::loadTexture(SDL_Renderer& renderer, std::string name) {

}

SDL_Texture* Texture::get() {
    return m_texture;
}
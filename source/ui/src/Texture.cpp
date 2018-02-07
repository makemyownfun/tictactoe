#include <iostream>

#include <SDL.h>

#include "Texture.h"
#include "constants.h"

// currently only loads bitmaps
// adding support for other file formats requires SDL_Image
bool Texture::loadTexture(SDL_Renderer& renderer, std::string name) {
    // Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP((TEXTURE_DIR+name).c_str());
    if(loadedSurface == nullptr ) {
        std::cout << "Unable to load image " << name << 
        "\nSDL_image Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    // Create texture from surface pixels
    m_texture = SDL_CreateTextureFromSurface(&renderer, loadedSurface);
    if(m_texture == nullptr ){
        std::cout << "Unable to create texture from " << name << 
        "\nSDL Error: " << SDL_GetError() << std::endl;
    }

    // Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

    return true;
}

SDL_Texture* Texture::get() {
    return m_texture;
}
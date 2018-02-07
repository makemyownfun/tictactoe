#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class SDL_Renderer;
class SDL_Texture;

class Texture {
    SDL_Texture* m_texture;

public:
    bool loadTexture(SDL_Renderer& renderer, std::string name);
    SDL_Texture* get();
};

#endif
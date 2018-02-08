#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <unordered_map>

#include <SDL.h>

#include "Texture.h"

class SDL_Renderer;

class UIelement {
    SDL_Rect m_clip;
    SDL_Rect m_dest;
    std::unordered_map<std::string,Texture> m_textures;
    std::string m_currTexture;

public:
    virtual ~UIelement() = default;

    void render(SDL_Renderer& renderer);
    void addTexture(std::string name, Texture& texture);
};

#endif
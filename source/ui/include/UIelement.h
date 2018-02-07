#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <SDL.h>

#include "Texture.h"

class SDL_Renderer;

class UIelement {
    SDL_Rect m_clip;
    SDL_Rect m_dest;
    Texture* m_texture;

public:
    void render(SDL_Renderer& renderer);
};

#endif
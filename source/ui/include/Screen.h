#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <memory>

#include "UIelement.h"

class SDL_Renderer;

class Screen {
    int m_width;
    int m_height;
    SDL_Texture* m_screenTexture;
    SDL_Color m_backgroundColor;
    std::vector<std::unique_ptr<UIelement>> m_children;

public:
    void init(int width, int height);
    bool handleEvents();
    void update();
    void display(SDL_Renderer& renderer);
};

#endif
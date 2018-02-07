#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

#include "UIelement.h"

class Screen {
    SDL_Renderer* m_renderer;
    int m_width;
    int m_height;
    SDL_Texture* m_screenTexture;
    SDL_Color m_backgroundColor;
    std::vector<std::unique_ptr<UIelement>> m_children;
    std::unordered_map<std::string,std::unique_ptr<Texture>> m_textures;

    bool loadTextures();

public:
    bool init(SDL_Window& window);
    bool handleEvents();
    void update();
    void display();
    void cleanup();
};

#endif
#ifndef SCREEN_H
#define SCREEN_H

class SDL_Renderer;

class Screen {
    SDL_Texture* m_screenTexture;
    int m_width;
    int m_height;

public:
    void init(int width, int height);
    bool handleEvents();
    void update();
    void display(SDL_Renderer& renderer);
};

#endif
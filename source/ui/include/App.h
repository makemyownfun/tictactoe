#ifndef APP_H
#define APP_H

#include <memory>

class SDL_Window;
class SDL_Renderer;
class Screen;

class App {
    int m_screenWidth;
    int m_screenHeight;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    Screen* m_screen;

public:
    bool init();
    void run();
    void cleanup();
};

#endif
#ifndef APP_H
#define APP_H

#include <memory>

class SDL_Window;
class SDL_Renderer;

class App {
    int m_screenWidth;
    int m_screenHeight;
    bool m_running;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    void handleEvents();

public:
    bool init();
    void run();
    void cleanup();
};

#endif
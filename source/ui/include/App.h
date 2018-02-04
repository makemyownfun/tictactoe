#ifndef APP_H
#define APP_H

class App {
    int m_screenWidth;
    int m_screenHeight;
    bool m_running;

    void handleEvents();

public:
    bool init();
    void run();
};

#endif
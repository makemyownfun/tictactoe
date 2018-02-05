#include <iostream>
#include <sstream>
#include <array>
#include <string>

#include "App.h"


int main(int argc, char* arv[]) {
    App app;
    if(!app.init()) {
        std::cout << "app failed to initialize" << std::endl;
        app.cleanup();
        return EXIT_FAILURE;
    }

    app.run();

   app.cleanup();

    return 0;
}
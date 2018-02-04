#include <iostream>
#include <sstream>
#include <array>
#include <string>

#include "App.h"


int main(int argc, char* arv[]) {
    App app;
    if(!app.init()) {
        std::cout << "app failed to initialize\n";
        return EXIT_FAILURE;
    }

    app.run();

    return 0;
}
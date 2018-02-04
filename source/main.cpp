#include <iostream>
#include <sstream>
#include <array>
#include <string>

#include "App.h"


int main(int argc, char* arv[]) {
    App app;
    if(!app.init()) {
        std::cout << "app failed to init\n";
        return EXIT_FAILURE;
    }

    return 0;
}
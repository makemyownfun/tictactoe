project(gameLogic)

include_directories(include)

set(SOURCES
    src/GameState.cpp
)

#Generate the shared library from the sources
add_library(gameLogic SHARED ${SOURCES})
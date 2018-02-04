project(ui)

include_directories(include)

set(SOURCES
    src/App.cpp
)

# add external dependencies
# SDL2
set(SDL_SHARED_ENABLED_BY_DEFAULT ON) 
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#Generate the shared library from the sources
add_library(ui SHARED ${SOURCES})
target_link_libraries( ui ${SDL2_LIBRARY} )
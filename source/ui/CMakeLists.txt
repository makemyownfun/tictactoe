project(ui)


set(RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources )

configure_file (
	${CMAKE_CURRENT_SOURCE_DIR}/include/constants.h.in
	${CMAKE_CURRENT_SOURCE_DIR}/include/constants.h
)

set(SOURCES
    src/App.cpp
    src/Screen.cpp
    src/UIelement.cpp
    src/Texture.cpp
)

#Generate the shared library from the sources
add_library(ui SHARED ${SOURCES})

# add external dependencies
# SDL2
find_package(SDL2)
if(NOT SDL2_FOUND)
    message(STATUS "building SDL2 from source since it wasnt found")
    message(WARNING "building sdl2 from source requires mercurial")

    set(SDL_TARGET "sdl2")
    list(APPEND CMAKE_ARGS "-DSDL_STATIC=OFF")
    list(APPEND CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${LIB_DIR}/${SDL_TARGET}")
    ExternalProject_Add(
        ${SDL_TARGET}
        HG_REPOSITORY http://hg.libsdl.org/SDL
        HG_TAG release-2.0.7
        PREFIX ${LIB_DIR}
        CMAKE_ARGS ${CMAKE_ARGS}
    )

    set(SDL2_INCLUDE_DIR ${LIB_DIR}/${SDL_TARGET}/include/SDL2)
    find_library(SDL2_LIBRARY
	    NAMES SDL2
	    PATH_SUFFIXES lib
	    PATHS ${LIB_DIR}/${SDL_TARGET}
    )

    add_dependencies(ui ${SDL_TARGET})
endif()

include_directories(include)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries( ui ${SDL2_LIBRARY} )




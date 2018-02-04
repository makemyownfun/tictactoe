# add top level source code
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

    PARENT_SCOPE
)

# include all headers from each of our game modules
set(INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}/gameLogic/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/include

    PARENT_SCOPE
)

# tell the top level cmake file the names of all of our modules
set(PROJECT_LIBS 
    gameLogic
    ui
    
    PARENT_SCOPE
)

# build each game module
add_subdirectory(gameLogic)
add_subdirectory(ui)

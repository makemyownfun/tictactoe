cmake_minimum_required(VERSION 3.1)
project (tictactoe)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
    message(FATAL_ERROR "You must set your binary directory different from your source")
endif()

# set some variables
set( EXE                            "tictactoe"             )
set( BIN_DIR                        ${CMAKE_SOURCE_DIR}/bin )
set( CMAKE_CXX_STANDARD             11                      )
set( CMAKE_CXX_STANDARD_REQUIRED    ON                      )
set( CMAKE_CXX_EXTENSIONS           OFF                     )

# helps while using VS Code
include(CMakeToolsHelpers OPTIONAL) 

# make sure the binary is put in the bin dir
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR} )

# add all of our source code
add_subdirectory(source)

add_executable( ${EXE} ${SOURCES} )
include_directories( ${INCLUDE_DIRS} )
target_link_libraries( ${EXE} ${PROJECT_LIBS} )

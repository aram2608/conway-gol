add_library(conways_gollib
    gollib/grid.cpp
    gollib/simulation.cpp
)

find_package(raylib 3.0 REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(conways_gollib
    PUBLIC
    raylib
    glfw
)

target_include_directories(conways_gollib
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/gollib/
)

target_compile_options(conways_gollib
    PRIVATE
    -Wall 
    -Wextra 
    -Wpedantic 
    -Wconversion
    -Wpessimizing-move
    -Wredundant-move
    -Wmove
    -Wrange-loop-construct
)

add_executable(conways_gol
    app/main.cpp
)

# raylib and glfw are propogated since they are public in the library
target_link_libraries(conways_gol PRIVATE conways_gollib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if(APPLE)
    target_link_libraries(conways_gol
        PRIVATE
            "-framework Cocoa"
            "-framework IOKit"
            "-framework OpenGL"
    )
endif()
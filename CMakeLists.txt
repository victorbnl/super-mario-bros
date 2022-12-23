project(SuperMarioBros)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Target
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# Headers
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)

# SDL
set(LIBARIES SDL2 SDL2_image)
target_link_libraries(${CMAKE_PROJECT_NAME} ${LIBARIES})

# Assets
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Build level
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets/levels)
execute_process(
    COMMAND tiled ${CMAKE_CURRENT_SOURCE_DIR}/levels/level.tmx --export-map ${CMAKE_BINARY_DIR}/assets/levels/level.csv
)

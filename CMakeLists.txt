project(SuperMarioBros)
cmake_minimum_required(VERSION 3.0)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Target
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# Headers
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)

# SDL2
target_link_libraries(${CMAKE_PROJECT_NAME} SDL2)
# SDL2_image
target_link_libraries(${CMAKE_PROJECT_NAME} SDL2_image)

# Assets
file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Build level
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/levels)
execute_process(
    COMMAND tiled-export ${CMAKE_CURRENT_SOURCE_DIR}/levels/level.tmx ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/levels/level.csv
)

project(SuperMarioBros)
cmake_minimum_required(VERSION 3.25)

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

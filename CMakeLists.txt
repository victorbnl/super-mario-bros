project(SuperMarioBros)
cmake_minimum_required(VERSION 3.25)

set(CMAKE_BUILD_TYPE Debug)

add_executable(smb src/main.cpp)

add_subdirectory(src)
target_link_libraries(smb smb_lib)

set(LIBARIES SDL2 SDL2_image)
target_link_libraries(smb ${LIBARIES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

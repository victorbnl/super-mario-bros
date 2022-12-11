project(SuperMarioBros)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES main.cpp game.cpp ltexture.cpp character.cpp)
add_executable(smb ${SOURCES})

set(LIBARIES SDL2 SDL2_image)
target_link_libraries(smb ${LIBARIES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

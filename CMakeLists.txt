project(SuperMarioBros)

set(SOURCES main.cpp ltexture.cpp character.cpp)
add_executable(smb ${SOURCES})

set(LIBARIES SDL2 SDL2_image)
target_link_libraries(smb ${LIBARIES})

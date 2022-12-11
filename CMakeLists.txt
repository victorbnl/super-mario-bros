project(SuperMarioBros)

set(SOURCES main.cpp)
add_executable(smb ${SOURCES})

set(LIBARIES SDL2)
target_link_libraries(smb ${LIBARIES})

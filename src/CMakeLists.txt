set(
    SOURCES
    game.cpp
    ltexture.cpp
    character.cpp
    collisions.cpp
    level/tiles.cpp
    level/level.cpp
    level/csv.cpp
)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})

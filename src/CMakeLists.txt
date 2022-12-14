set(
    SOURCES
    game.cpp
    ltexture.cpp
    character.cpp
    collisions/collisions.cpp
    collisions/math.cpp
    level/tile.cpp
    level/level.cpp
    level/csv.cpp
    level/tileset.cpp
)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})

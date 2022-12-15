set(
    SOURCES
    game.cpp
    ltexture.cpp
    character.cpp
    camera.cpp
    physics/physics.cpp
    physics/collisions/solve_collisions.cpp
    physics/collisions/collisions.cpp
    physics/collisions/math.cpp
    level/tile.cpp
    level/level.cpp
    level/csv.cpp
    level/tileset.cpp
)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})

set(
    SOURCES
    game.cpp
    character.cpp
    camera.cpp
    structures.cpp
    render/ltexture.cpp
    render/window.cpp
    physics/rigidbody.cpp
    physics/physics.cpp
    physics/collisions/math.cpp
    physics/collisions/get_adjacent_tiles.cpp
    physics/collisions/solve_collisions.cpp
    physics/collisions/collisions.cpp
    level/tile.cpp
    level/level.cpp
    level/csv.cpp
    level/tileset.cpp
)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})

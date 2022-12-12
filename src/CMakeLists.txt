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

add_library(smb_lib ${SOURCES})

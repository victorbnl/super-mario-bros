#include <iostream>
#include <vector>
#include <array>
#include <SDL2/SDL.h>

#include "tiles.h"
#include "ltexture.h"

const int SCREEN_HEIGHT = 48*10;

const int TILE_WIDTH = 48;
const int TILE_HEIGHT = 48;

Tile::Tile(int x, int y, LTexture* texture)
{
    mPosX = x;
    mPosY = y;
    mTexture = texture;
}

void Tile::render(SDL_Renderer* renderer)
{
    mTexture->render(renderer, mPosX, mPosY);
}

LTexture* getTileSet(SDL_Renderer* renderer)
{
    static LTexture tileSet[4] = {
        LTexture(),
        LTexture(),
        LTexture(),
        LTexture()
    };

    tileSet[0].loadFromFile(renderer, "assets/grass.png");
    tileSet[1].loadFromFile(renderer, "assets/dirt.png");
    tileSet[2].loadFromFile(renderer, "assets/bricks.png");
    tileSet[3].loadFromFile(renderer, "assets/luck.png");

    return tileSet;
}

std::vector<std::vector<int>> getTilesTypeArray()
{
    // Load file
    std::ifstream map("assets/level.csv");
    if (map.fail())
    {
        std::cout << "Failed to load map";
    }

    // Read file
    std::vector<std::vector<int>> tiles;
    std::string line = "";
    while (std::getline(map, line))
    {
        // Read line elements
        std::vector<int> lineTiles;
        int pos = 0;
        int currentPos = 0;
        while ((pos = line.find(",", currentPos)) != std::string::npos)
        {
            // Get the tile type & add it to the line elements list
            std::string token = line.substr(currentPos, pos-currentPos);
            int tileType = std::stoi(token);
            lineTiles.push_back(tileType);
            currentPos = pos+1;
        }

        // Add line elements to parsed tiles list
        tiles.push_back(lineTiles);
    }

    return tiles;
}

std::vector<Tile*> getTiles(SDL_Renderer* renderer)
{
    // Parse tiles file
    std::vector<std::vector<int>> tilesTypes = getTilesTypeArray();

    // Get textures
    LTexture* tileSet = getTileSet(renderer);

    // Generate tiles list
    std::vector<Tile*> tiles;
    // For each line of tiles
    int x, y;
    for (int i = 0; i < size(tilesTypes); i++)
    {
        y = SCREEN_HEIGHT-(size(tilesTypes)*48)+i*TILE_HEIGHT;
        // For each tile of line
        for (int j = 0; j < size(tilesTypes[i]); j++)
        {
            x = j*TILE_WIDTH;
            int type = tilesTypes[i][j];
            if (type > -1)
            {
                LTexture* texture = (tileSet+tilesTypes[i][j]);
                tiles.push_back(new Tile(x, y, texture));
            }
        }
        x = 0;
    }

    return tiles;
}

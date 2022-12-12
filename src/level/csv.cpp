#include <string>
#include <fstream>
#include <iostream>

#include "csv.h"

std::vector<std::vector<int>> parseCSVLevel(std::string path)
{
    // Load file
    std::ifstream map(path);
    if (map.fail())
    {
        std::cout << "Failed to load level data" << std::endl;
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

#pragma once

#include <SDL2/SDL.h>

enum GridType
{
  GRID,
  BOARDER,
};

class Grid
{
public:
  // Function to render the grid
  void static render(SDL_Renderer *renderer, int gridX, int gridY, GridType gridType);
};

#include "grid.hpp"
#include "config.hpp"

void Grid::render(SDL_Renderer *renderer, int gridX, int gridY, GridType gridType)
{
  SDL_SetRenderDrawColor(renderer, 0x55, 0x55, 0x55, 255); // Gray grid lines

  SDL_Rect cell;
  if (gridType == GRID)
  {
    int cell_size = GRID_DIM / GRID_SIZE;
    cell.w = cell_size;
    cell.h = cell_size;

    for (int i = 0; i < GRID_SIZE; i++)
    {
      for (int j = 0; j < GRID_SIZE; j++)
      {
        cell.x = gridX + (i * cell_size);
        cell.y = gridY + (j * cell_size);
        SDL_RenderDrawRect(renderer, &cell);
      }
    }
  }
  else
  {
    cell.w = GRID_DIM;
    cell.h = GRID_DIM;
    cell.x = gridX;
    cell.y = gridY;

    SDL_RenderDrawRect(renderer, &cell);
  }
}

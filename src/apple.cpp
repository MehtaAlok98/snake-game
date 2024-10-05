#include "apple.hpp"
#include "snake.hpp"
#include "config.hpp"
#include <cstdlib>

Apple::Apple()
{
  this->generate();
}

void Apple::generate()
{
  this->x = rand() % GRID_SIZE;
  this->y = rand() % GRID_SIZE;
}

void Apple::render(SDL_Renderer *renderer, int gridX, int gridY)
{
  SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 255); // Red color for apple
  int seg_size = GRID_DIM / GRID_SIZE;

  SDL_Rect apple;
  apple.w = seg_size;
  apple.h = seg_size;
  apple.x = gridX + this->x * seg_size;
  apple.y = gridY + this->y * seg_size;
  SDL_RenderFillRect(renderer, &apple);
}

void generateValidApple(Apple &apple, Snake &snake)
{
  do
  {
    apple.generate();
  } while (snake.isAppleOnSnake(apple.x, apple.y));
}

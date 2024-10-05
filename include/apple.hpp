#pragma once

#include <SDL2/SDL.h>

class Snake; // Forward declaration of Snake class

class Apple
{
public:
  int x, y;

  Apple();

  void generate();
  void render(SDL_Renderer *renderer, int gridX, int gridY);
};

void generateValidApple(Apple &apple, Snake &snake);

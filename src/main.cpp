#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include "config.hpp"
#include "grid.hpp"
#include "snake.hpp"
#include "apple.hpp"

int main(int argc, char *argv[])
{
  srand(time(0)); // Seed for random number generation

  Snake snake;
  snake.increase();

  Apple apple;
  generateValidApple(apple, snake);

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  SDL_Window *window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  if (!window)
  {
    std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return EXIT_FAILURE;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer)
  {
    std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_FAILURE;
  }

  int gridX = (WINDOW_WIDTH / 2) - (GRID_DIM / 2);
  int gridY = (WINDOW_HEIGHT / 2) - (GRID_DIM / 2);

  bool gameOver = false;
  SDL_Event e;

  while (!gameOver)
  {
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
        gameOver = true; // Exit if the window close button is clicked
      }
      else if (e.type == SDL_KEYDOWN)
      {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
          snake.changeDirection(SNAKE_UP);
          break;
        case SDLK_DOWN:
          snake.changeDirection(SNAKE_DOWN);
          break;
        case SDLK_LEFT:
          snake.changeDirection(SNAKE_LEFT);
          break;
        case SDLK_RIGHT:
          snake.changeDirection(SNAKE_RIGHT);
          break;
        case SDLK_ESCAPE:
          gameOver = true; // Exit if the ESC key is pressed
          break;
        }
      }
    }

    snake.move();

    if (snake.checkCollisionWithApple(apple.x, apple.y))
    {
      snake.increase();
      generateValidApple(apple, snake);
    }

    if (snake.checkSelfCollision())
    {
      gameOver = true;
      std::cout << "Game Over! Snake collided with itself!" << std::endl;
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // Black background
    SDL_RenderClear(renderer);

    // render_grid(renderer, gridX, gridY);
    Grid::render(renderer, gridX, gridY, BOARDER);
    snake.render(renderer, gridX, gridY);
    apple.render(renderer, gridX, gridY);

    SDL_RenderPresent(renderer);

    SDL_Delay(100); // Delay to control the frame rate
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}

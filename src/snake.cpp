// snake.cpp
#include "snake.hpp"
#include "config.hpp"
#include <cstdlib> // For rand()

SnakeSegment::SnakeSegment(int initX, int initY, Direction initDir)
    : x(initX), y(initY), dir(initDir), next(nullptr) {}

Snake::Snake()
{
  // Initialize snake in a random position within the grid
  int initX = rand() % GRID_SIZE;
  int initY = rand() % GRID_SIZE;
  head = std::make_shared<SnakeSegment>(initX, initY, SNAKE_UP);
  tail = head;
}

void Snake::increase()
{
  auto newSegment = std::make_shared<SnakeSegment>(tail->x, tail->y, tail->dir);
  tail->next = newSegment;
  tail = newSegment;
}

void Snake::move()
{
  // Store current head position and direction to shift segments
  int prevX = head->x;
  int prevY = head->y;
  Direction prevDir = head->dir;

  // Move the head based on the direction
  switch (head->dir)
  {
  case SNAKE_UP:
    head->y = (head->y - 1 + GRID_SIZE) % GRID_SIZE;
    break;
  case SNAKE_DOWN:
    head->y = (head->y + 1) % GRID_SIZE;
    break;
  case SNAKE_LEFT:
    head->x = (head->x - 1 + GRID_SIZE) % GRID_SIZE;
    break;
  case SNAKE_RIGHT:
    head->x = (head->x + 1) % GRID_SIZE;
    break;
  }

  // Move the rest of the segments
  auto track = head->next;
  while (track != nullptr)
  {
    int tempX = track->x;
    int tempY = track->y;
    Direction tempDir = track->dir;

    track->x = prevX;
    track->y = prevY;
    track->dir = prevDir;

    prevX = tempX;
    prevY = tempY;
    prevDir = tempDir;
    track = track->next;
  }
}

void Snake::changeDirection(Direction newDir)
{
  // Prevent reversing into itself
  if ((head->dir == SNAKE_UP && newDir == SNAKE_DOWN) ||
      (head->dir == SNAKE_DOWN && newDir == SNAKE_UP) ||
      (head->dir == SNAKE_LEFT && newDir == SNAKE_RIGHT) ||
      (head->dir == SNAKE_RIGHT && newDir == SNAKE_LEFT))
  {
    return;
  }
  head->dir = newDir;
}

bool Snake::checkCollisionWithApple(int appleX, int appleY)
{
  return (head->x == appleX && head->y == appleY);
}

bool Snake::checkSelfCollision()
{
  auto track = head->next;
  while (track != nullptr)
  {
    if (head->x == track->x && head->y == track->y)
    {
      return true; // Collision detected
    }
    track = track->next;
  }
  return false;
}

bool Snake::isAppleOnSnake(int appleX, int appleY)
{
  auto track = head;
  while (track != nullptr)
  {
    if (track->x == appleX && track->y == appleY)
    {
      return true;
    }
    track = track->next;
  }
  return false;
}

void Snake::render(SDL_Renderer *renderer, int gridX, int gridY)
{
  SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0x00, 255); // Green color for snake
  int seg_size = GRID_DIM / GRID_SIZE;

  SDL_Rect seg;
  seg.w = seg_size;
  seg.h = seg_size;

  auto track = head;
  while (track != nullptr)
  {
    seg.x = gridX + track->x * seg_size;
    seg.y = gridY + track->y * seg_size;
    SDL_RenderFillRect(renderer, &seg);
    track = track->next;
  }
}

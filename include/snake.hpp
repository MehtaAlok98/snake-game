#pragma once

#include <SDL2/SDL.h>
#include <memory>

enum Direction
{
  SNAKE_UP,
  SNAKE_DOWN,
  SNAKE_LEFT,
  SNAKE_RIGHT
};

// SnakeSegment class representing each segment of the snake
class SnakeSegment
{
public:
  int x, y;
  Direction dir;
  std::shared_ptr<SnakeSegment> next;

  SnakeSegment(int initX, int initY, Direction initDir);
};

// Snake class managing snake's movement, growth, and rendering
class Snake
{
public:
  std::shared_ptr<SnakeSegment> head;
  std::shared_ptr<SnakeSegment> tail;

  Snake();

  void increase();
  void move();
  void changeDirection(Direction newDir);
  bool checkCollisionWithApple(int appleX, int appleY);
  bool checkSelfCollision();
  bool isAppleOnSnake(int appleX, int appleY);
  void render(SDL_Renderer *renderer, int gridX, int gridY);
};

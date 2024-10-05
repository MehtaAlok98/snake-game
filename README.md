# Snake Game

A classic Snake Game implemented in C++. This project serves as a fun and educational way to practice your C++ programming skills and understand game development concepts.

## Features

- Playable Snake Game with basic controls
- Scoring system
- Simple graphical interface

## Requirements

Before running the game, make sure you have the following installed on your system:

- C++ compiler (e.g., `g++`)
- CMake (for building the project)
- Conan (for managing dependencies)

### Optional

- [Ninja Build System](https://ninja-build.org/) (recommended for faster builds)

## Getting Started

## Install conan

```python
pip install conan
```

#### Conan Profile Detection

You can view the detected profile settings by running:

```bash
conan profile detect # this will detect and generate default profile
conan profile detect --name SnakeGame
```

This command will provide you with a summary of the current profile settings at `~/.conan2/profiles/SnakeGame`, including the following:

```plaintext
[settings]
arch=x86_64
build_type=Release
compiler=gcc
compiler.cppstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=11
os=Linux

[conf]
tools.cmake.cmaketoolchain:generator=Ninja
tools.system.package_manager:mode=install
```

### Clone the Repository

```bash
git clone https://github.com/MehtaAlok98/snake-game.git
cd snake-game
```

### Install Dependencies with Conan

To manage the dependencies of the project, we use Conan. Install the necessary dependencies by running the following command:

```bash
conan install . --build=missing -s build_type=Release -pr=SnakeGame
```

### Build the Project

If you have Conan and CMake installed, you can build the project as follows:

1. Run CMake to generate the build system files:

   ```bash
   cmake -G Ninja -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_BUILD_TYPE=Release -S . -B build/Release
   ```

2. Build the project:

   ```bash
   cmake --build build/Release
   ```

### Run the Game

After building the project, you can run the game by executing the following command in the build directory:

```bash
./build/Release/bin/snake 
```

## Controls

- Use arrow keys to control the snake direction.
- Eat the food (represented as a square) to grow your snake and increase your score.
- Avoid running into the walls or into yourself!

---
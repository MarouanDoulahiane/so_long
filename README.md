# 🎮 so_long

## About
The `so_long` project is a small 2D game developed as part of the 42 curriculum. It provides an opportunity to work with textures, sprites, and basic gameplay elements.

This project aims to enhance skills in window management, event handling, colors, textures, and more, using the MiniLibX graphical library.

For more detailed information, refer to the [subject of this project](https://github.com/Surfi89/42cursus/blob/main/Subject%20PDFs/02_so_long.en.pdf).

## Usage

### Requirements
To compile and run the program, ensure you have:
- `cc` compiler
- Standard C libraries

### Instructions

1. **Compiling**

Navigate to the project directory and execute:
```shell
$ make
```
or
```shell
$ make bonus
```
to enable animated sprites and enemy characters.

## 📋 How to play

To play the minigame, launch it with the following shell command:
```shell
$ ./so_long <map_name>.ber
```
or
```shell
$ ./so_long_bonus <map_name>.ber
```

Several sample maps are provided for testing:
- "map1.ber": Simple map
- "map2.ber": Larger map with more collectibles
- "map3.ber": Includes enemies for bonus gameplay

### Controls
- Use WASD keys to move UP, LEFT, DOWN, or RIGHT
- Press ESC or click the red cross to quit the game
- Touching an enemy results in game over
- Collect all items and return to the exit to win

### Map Rules
- Map file extension must be `.ber`
- Must be rectangular with `1` marking map limits
- Must contain one exit, one player, and at least one collectible
- Allowed characters:

| Character | Object                  |
|-----------|-------------------------|
| 1         | Obstacle                |
| 0         | Empty                   |
| C         | Collectible             |
| E         | Exit                    |
| P         | Player starting position|
| B         | Enemy position          |

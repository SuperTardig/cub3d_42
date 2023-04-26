# Cub3d
The goal of this 42 school project is to create a textured raycasting engine and a map parser to be able to play the game. This project helps us learn more indepht about video game devellopement and graphical programming. This is another group project, I mainly worked on the engine. We must use the MiniLibX (like in so_long, another 42 school project I previously did)
## Mandatory
The mandatory requirement for this project are as followed:
  - Wall texture depending on the direction which you are facing. They are given in the map file
  - The ceiling and floor must have a colour given in the map file
  - The left and right arrow keys make you look left and right respectively
  - Movement is done using the `'W'`, `'A'`, `'S'` and `'D'`
  - The program takes the path to a file ending in `.cub`
  - The map must be:
    - Composed of "1" and "0" for walls and spaces and one of the following for the player starting position and orientation: "N", "S", "E" and "W"
    - It must be closed/surrounded by walls
    - It must have 4 paths to the texture files and 2 RGB values for the floor and ceiling
## Bonus
The bonus requirement for this project are left pretty open to let people be creative. We implemented the following functionnalitys:
  - Wall collisions
  - A minimap which is centered arround the player
  - Ambience song and sound effect
  - Rotation of the point of view with the mouse
  - Animation
## Usage
To be able to use this project, you must have `GLFW` for the MiniLibX to function. You might have to change the path of this libary in the Makefile depending on where it is installed. To use this project, you need to:
1. Clone this repository
2. Go to the root of the repository and use `make` or `make bonus` depending on which version you want
3. Run `./cub3D <path to map file>` or `./cub3D_bonus <path to map file>`

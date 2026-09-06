*This project has been created as part of the 42 curriculum by apolleux, lchamard*

# Description

cub3D is a raycasting engine inspired by early first-person games such as Wolfenstein 3D. The program reads a `.cub` configuration file describing a map, wall textures, floor and ceiling colors, and the player's starting position and orientation, then renders a real-time 3D view of the map from the player's perspective. The player can move and rotate inside the map using the keyboard, and the view updates accordingly.

The project is split into two main parts: a parser that reads and validates the `.cub` file (map structure, textures, colors, player spawn), and a renderer that uses raycasting to project the 2D map into a 3D view.

# Instructions

## Compilation

```
make
```

This builds the `cub3D` executable and compiles the required libraries (libft, MinilibX or the MLX library used by this project).

Other available rules:

```
make clean   # removes object files
make fclean  # removes object files and the executable
make re      # fclean + make
```

## Usage

```
./cub3D <path/to/map.cub>
```

The map file must have a `.cub` extension. See the `Description` section above and the map format requirements below.

## Map file format

A valid `.cub` file must define, in any order:

- `NO`, `SO`, `WE`, `EA`: paths to the north, south, west, and east wall textures
- `F`: floor color, as `R,G,B` (values between 0 and 255)
- `C`: ceiling color, as `R,G,B` (values between 0 and 255)
- The map itself, made of `0` (empty space), `1` (wall), and one of `N`, `S`, `E`, `W` (player starting position and orientation)

The map must be surrounded by walls. Empty lines are only tolerated between the identifiers listed above, not within the map itself.

## Controls

- Arrow keys or WASD: move the player
- Left / right arrow keys or mouse: rotate the camera
- ESC or window close button: quit the program

# Resources

- Lode Vandevenne's raycasting tutorial: https://lodev.org/cgtutor/raycasting.html
- The Dining Philosophers-adjacent 42 subject and this project's own subject PDF for the exact `.cub` format and constraints
- MinilibX / MLX documentation for window and image handling

## AI usage

An AI assistant (Claude) was used during this project as a tutor rather than a code generator, in line with the guidelines described in the subject:

- Explaining concepts before implementation: threads and mutexes were first covered on the Philosophers project, and similar step-by-step explanations were used here for raycasting theory and parsing strategy.
- Reviewing hand-written code for bugs, memory leaks, and data races (validated afterward with Valgrind and Helgrind), rather than having code written from scratch.
- Helping debug specific issues (double frees, use-after-free, incorrect loop logic) by pointing to the exact cause once relevant code and tool output were shared.
- Discussing the overall structure of the parser (splitting file validation into a directives-checking phase and a map-checking phase) before writing the corresponding functions.

All code in this repository was written and is understood by its authors, who can explain and justify any part of it during evaluation.

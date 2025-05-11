# Cub3D

A simple 3D raycasting engine built in C using the MiniLibX library. Cub3D is a project inspired by early first-person shooter games like Wolfenstein 3D, where you learn to render a 3D scene from a 2D map using the raycasting technique.

---

## Table of Contents

- [Subject](#subject)
- [Learning Objectives](#learning-objectives)
- [Project Structure](#project-structure)
- [Installation & Compilation](#installation--compilation)
- [Usage](#usage)
- [Map File Format (`.cub`)](#map-file-format-cub)
- [Controls](#controls)
- [How It Works](#how-it-works)
  - [Parsing](#parsing)
  - [Raycasting](#raycasting)
  - [Rendering](#rendering)
- [Features & Extensions](#features--extensions)
- [Contributors](#contributors)

---

## Subject

Cub3D is a learning project where you build a basic 3D engine from scratch in C. You'll use fundamental concepts like:

- 2D map representation and parsing
- Raycasting algorithm for 3D projection
- Handling user input for movement and looking around
- Rendering walls, floor/ceiling, and textures with MiniLibX

This mimics the techniques used in early 1990s games.

## Learning Objectives

- Master file parsing and string manipulation in C
- Practice dynamic memory management
- Understand and implement the raycasting algorithm
- Explore graphics programming with MiniLibX on Linux
- Work with data structures to represent sprites and textures

## Project Structure

```
├── Get_next_line/     # Get Next Line utility functions
├── includes/          # Header files
│   └── *.h
├── libft/             # Custom C utility library
├── minilibx-linux/    # MiniLibX graphics library
├── parsing/           # Map parsing and validation
├── raycasting/        # Core rendering functions
├── raycasting_bonnus/ # Optional bonus features
├── textures/          # Wall and sprite textures
├── big.cub            # Example map file
├── cub3D.c            # Main entry point
├── Makefile           # Build rules
└── map.cub            # Sample map
```

## Installation & Compilation

1. Clone the repository:
   ```zsh
   git clone https://github.com/LAHMAMI1/Cub3D && cd Cub3D
   ```
2. Build the project and dependencies:
   ```zsh
   make
   ```
3. Run the program with a `.cub` map file:
   ```zsh
   ./cub3D map.cub
   ```

> **Note:** Ensure X11 development headers are installed on your system for MiniLibX.

## Usage

```zsh
./cub3D <path_to_map_file>.cub
```

Example:
```zsh
./cub3D big.cub
```

## Map File Format (`.cub`)

A `.cub` file defines the map and textures:

```
NO ./textures/north.xpm   # North wall texture
SO ./textures/south.xpm   # South wall texture
WE ./textures/west.xpm    # West wall texture
EA ./textures/east.xpm    # East wall texture
F 220,100,0               # Floor RGB color
C 225,30,0                # Ceiling RGB color

111111
100001
10N001   # Initial player position facing North
100001
111111
```

- `1` = wall
- `0` = empty space
- `N/S/E/W` = player start position and orientation

## Controls

- W / ↑ : Move forward
- S / ↓ : Move backward
- A      : Strafe left
- D      : Strafe right
- ←      : Turn left
- →      : Turn right
- ESC    : Quit

## How It Works

### Parsing
- Read the `.cub` file line by line.
- Extract texture paths, floor/ceiling colors, and map layout.
- Validate enclosure by walls and a single valid player start.

### Raycasting
- For each vertical stripe on screen, cast a ray from the player position.
- Check intersections with horizontal and vertical grid lines.
- Choose the closest hit to determine wall distance.
- Calculate line height based on distance to simulate 3D.

### Rendering
- Use MiniLibX to open a window and draw pixels.
- Textures are loaded from XPM files.
- Floor and ceiling are drawn as solid colors.
- Walls are textured by sampling based on ray hit.
- Optional sprite support for bonus features.

## Features & Extensions

- Textured walls with perspective correction
- Floor and ceiling coloring
- Sprite rendering (enemies, objects)
- Mini-map view (2D top-down)
- Additional bonus features under `raycasting_bonnus/`

## Contributors

- **Oussama Lahmami (*Parsing Part*)**: [GitHub Profile](https://github.com/LAHMAMI1)
- **Fatima ezzahrae Diraa (*Rendering Part*)**: [GitHub Profile](https://github.com/Raven-79)

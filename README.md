# 2048 Game

The 2048 game is a simple yet addictive puzzle game where the objective is to slide and merge tiles with the same value to create a tile with the number 2048. The game is played on a 4x4 grid, and new tiles (either 2 or 4) are added to the grid after each move.

## How to Play

Use the following keys to move the tiles in the respective direction:
- 'W' or 'w': Move tiles up
- 'S' or 's': Move tiles down
- 'A' or 'a': Move tiles left
- 'D' or 'd': Move tiles right

Tiles will move in the chosen direction until they hit the edge of the grid or another tile. If two tiles with the same value collide, they merge into a single tile with double the value. After each move, a new tile is randomly placed in an empty cell on the grid.

The game ends when there are no more valid moves available, i.e., when all cells on the grid are filled, and no adjacent tiles have the same value.

## Dependencies

This C++ implementation of the 2048 game uses the following standard libraries:
- iostream: For input/output operations
- vector: For using vectors to represent the grid
- cstdlib: For rand() and srand() functions to generate random tiles
- ctime: For seeding srand() with the current time to get different random tiles on each run

## How the Code Works

1. `main()`: The main function initializes the game grid, displays the grid, and runs a loop until the game is over. It takes user input to move the tiles and updates the grid accordingly. After the game is over, it calculates and displays the final score.

2. `initializeGame()`: This function places two random tiles (either 2 or 4) on the grid to start the game.

3. `displayGrid()`: This function displays the current state of the game grid.

4. `placeRandomTile()`: This function places a new random tile (either 2 or 4) in an empty cell of the grid after each move.

5. `isGameOver()`: This function checks if the game is over by examining whether there are any empty cells on the grid or adjacent tiles with the same value.

6. `scoreCalculation()`: This function calculates the total score by adding up all the tile values on the grid.

7. `moveTilesUp()`, `moveTilesDown()`, `moveTilesLeft()`, `moveTilesRight()`: These functions handle the movement of tiles in the respective directions. They create a temporary grid, move and merge the tiles in the specified direction, and update the game grid with the new arrangement.

8. `mergeTiles()`: This function is called by the movement functions to merge adjacent tiles with the same value in a row or column. It doubles the value of the current tile and sets the value of the next tile to zero.

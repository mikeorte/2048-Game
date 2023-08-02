# Pseudocode for 2048 Game

## Main Function
1. Set constant N = 4  // The row and column size of the grid
2. Create Grid as a 2D vector of size N x N to represent the game grid

3. Call initializeGame() to place two random tiles on the grid
4. Call displayGrid() to display the initial state of the grid

5. While the game is not over (i.e., there are empty cells or adjacent tiles with the same value):
    6. Prompt the user to enter a move (W, S, A, D) to move tiles up, down, left, or right
    7. If the move is valid (W, S, A, D):
        8. Call the respective move function (moveTilesUp, moveTilesDown, moveTilesLeft, moveTilesRight)
        9. Call placeRandomTile() to add a new random tile to the grid
        10. Call displayGrid() to display the updated grid after the move

11. Display "Game Over!"
12. Call scoreCalculation() to calculate the final score
13. Display the final score

## initializeGame Function 
1. Call placeRandomTile(gameGrid) to add a random tile to the grid
2. Call placeRandomTile(gameGrid) to add another random tile to the grid

## displayGrid Function 
1. Display "2048 Game"
2. Display "-----------------------------"
3. For each row in gameGrid:
    4. For each element in the row:
        5. Display the element followed by a tab
    6. Display a new line after each row
7. Display "-----------------------------"

## placeRandomTile Function 
1. Repeat until an empty cell is found:
    2. Generate random row and column indices between 0 and N-1
    3. If the cell at (row, col) in gameGrid is empty:
        4. Generate a random number between 0 and 99
        5. If the random number is less than 80, set tileValue to 2, else set it to 4
        6. Set the cell at (row, col) in gameGrid to tileValue
        7. Break out of the loop

## isGameOver Function
1. For each row in gameGrid:
    2. For each element in the row:
        3. If the element is 0, return false  // The game is not over if there are empty cells
4. Return true  // All cells are filled, and the game is over

## scoreCalculation Function
1. Set score = 0
2. For each row in gameGrid:
    3. For each element in the row:
        4. Add the element value to score
5. Return score

## moveTilesUp Function 
1. Create tempGrid as a 2D vector of size N x N initialized with all zeros
2. For each column in gameGrid:
    3. Create tempCol as an empty vector to hold non-zero elements from the column
    4. For each row in gameGrid:
        5. If the cell at (row, col) is not zero, add the element to tempCol
    6. Call mergeTiles(tempCol) to merge adjacent tiles in tempCol
    7. For each row in tempCol:
        8. Set the corresponding cell in tempGrid to the element value
9. Copy tempGrid back to gameGrid to apply the changes

## moveTilesDown Function
- Similar to moveTilesUp with a reverse order

## moveTilesLeft Function 
1. Create tempGrid as a 2D vector of size N x N initialized with all zeros
2. For each row in gameGrid:
    3. Create tempRow as an empty vector to hold non-zero elements from the row
    4. For each column in gameGrid:
        5. If the cell at (row, col) is not zero, add the element to tempRow
    6. Call mergeTiles(tempRow) to merge adjacent tiles in tempRow
    7. For each column in tempRow:
        8. Set the corresponding cell in tempGrid to the element value
9. Copy tempGrid back to gameGrid to apply the changes

## moveTilesRight Function
- Similar to moveTilesLeft with a reverse order

## mergeTiles Function
1. Set i = 0  // Start index
2. Set j = 1  // Next index (i+1)
3. While j < row.size():  // Loop through the row and merge adjacent tiles with the same value
    4. If row[i] is equal to row[j] and row[i] is not zero:  // If adjacent tiles have the same value AND not zero, merge
        5. Double the value of the element at row[i]
        6. Set the value of the element at row[j] to zero
        7. Set i = j + 1  // Move the start index to the next element after the merged tiles
        8. Set j = i + 1  // Move the next index to the element after the start index
    9. Else:
        10. If the element at row[i] is zero and the element at row[j] is not zero:  // If the current tile is zero AND the next tile is not zero, swap
            11. Swap the elements at row[i] and row[j]  // Moves the non-zero tile towards the beginning of row
        12. Increment i and j by 1  // Move to the next pair of elements in the row to compare
13. End of mergeTiles function

#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand() functions
#include <ctime>   // for seeding srand() with the current time

const int N = 4; // The row and column size of the grid
using Grid = std::vector<std::vector<int>>; // makes Grid an alias, to avoid writing std::vector<std::vector<int>> a lot

//Function Prototypes
//Passing by reference is more effiecent since it will not create a new instance
void initializeGame(Grid& gameGrid);
void displayGrid(Grid& gameGrid);
void placeRandomTile(Grid& gameGrid);
bool isGameOver(Grid& gameGrid);
int scoreCalculation(Grid& gameGrid);
void moveTilesUp(Grid& gameGrid);
void moveTilesDown(Grid& gameGrid);
void moveTilesLeft(Grid& gameGrid);
void moveTilesRight(Grid& gameGrid);
void mergeTiles(std::vector<int>& row);

int main() {
    std::srand(static_cast<unsigned>(std::time(0))); //makes it random everytime

    Grid gameGrid(N, std::vector<int>(N, 0)); //Creates the grid and fills it with 0s

    initializeGame(gameGrid); //initalizes the game by placing 2 random files
    displayGrid(gameGrid); //displays the initial instance
    while (!isGameOver(gameGrid)) {

        char move;
        std::cout << "Enter 'W' to move up, 'S' to move down, 'A' to move left, or 'D' to move right: ";
        std::cin >> move;

        if (move == 'W' || move == 'w')
            moveTilesUp(gameGrid);
        else if (move == 'S' || move == 's')
            moveTilesDown(gameGrid);
        else if (move == 'A' || move == 'a')
            moveTilesLeft(gameGrid);
        else if (move == 'D' || move == 'd')
            moveTilesRight(gameGrid);
        else {
            std::cout << "Invalid move. Please try again." << std::endl;
            continue; // repeats while, to not add new tile or redisplay grid
        }

        placeRandomTile(gameGrid); //adds new tile
        displayGrid(gameGrid); //displays updated grid
    }
    std::cout << "Game Over!\n";
    int score = scoreCalculation(gameGrid); //gets score
    std::cout << "Your Score is: " << score << std::endl;

    return 0;
}

void initializeGame(Grid& gameGrid) {
    placeRandomTile(gameGrid); //adds new tile
    placeRandomTile(gameGrid); //adds new tile
}

void displayGrid(Grid& gameGrid) {
    std::cout << "2048 Game\n";
    std::cout << "-----------------------------\n";
    for (std::vector<int> row : gameGrid) { //for each row in gameGrid
        for ( int element : row) { //for each element in row
            std::cout << element << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "-----------------------------\n";
}

void placeRandomTile(Grid& gameGrid) { //places a random tile (either 2 or 4) in an empty cell
    bool emptyCellFound = false;
    while (!emptyCellFound) {
        int row = rand() % N; // Generate a random row within the grid size
        int col = rand() % N; // Generate a random column within the grid size

        if (gameGrid[row][col] == 0) { //finds empty cell
            // Generate a random number to determine tile value (80% for 2, 20% for 4)
            int randomValue = rand() % 100; // Generate a random number between 0 and 99

            int tileValue;
            if (randomValue < 80) {
                tileValue = 2;
            }
            else {
                tileValue = 4;
            }
            gameGrid[row][col] = tileValue; //adds to grid
            emptyCellFound = true; //found empty cell and filled it
        }
        //do nothing if empty cell not found
    }
}

bool isGameOver(Grid& gameGrid) {
    for (std::vector<int> row : gameGrid) { //for each row in gameGrid
        for (int element : row) { //for each element in row
            if (element == 0) {
                return false; // If any cell is empty, the game is not over
            }
        }
    }
    return true; // If all cells are filled, the game is over
}

int scoreCalculation(Grid& gameGrid) {
    int score = 0;
    for (std::vector<int> row : gameGrid) { //for each row in gameGrid
        for (int element : row) { //for each element in row
            score += element;
        }
    }
    return score;
}

void moveTilesUp(Grid& gameGrid) { 
    Grid tempGrid(N, std::vector<int>(N, 0)); //temp grid to hold non-zeros

    for (int col = 0; col < N; col++) {
        std::vector<int> tempCol; //temp col to hold non-zeros in coloumn
        for (int row = 0; row < N; row++) {
            if (gameGrid[row][col] != 0) {
                tempCol.push_back(gameGrid[row][col]); //adds non-zeros to tempCol
            }
        }
        mergeTiles(tempCol); //merge the tiles in the column 

        for (int row = 0; row < tempCol.size(); row++) { //replaces the tempGrid col with the merged tempCol
            tempGrid[row][col] = tempCol[row]; 
        }
    }

    gameGrid = tempGrid; //applies all the changes
}

void moveTilesDown(Grid& gameGrid) {
    Grid tempGrid(N, std::vector<int>(N, 0)); //temp grid to hold non-zeros

    for (int col = 0; col < N; col++) {
        std::vector<int> tempCol; //temp col to hold non-zeros in coloumn
        for (int row = 0; row < N; row++) {
            if (gameGrid[N - row - 1][col] != 0) { 
                tempCol.push_back(gameGrid[N - row - 1][col]); //adds non-zeros to tempCol, but in reverse (its down)
            }
        }
        mergeTiles(tempCol); //merge the tiles in the column 

        for (int row = 0; row < tempCol.size(); row++) { //replaces the tempGrid col with the merged tempCol
            tempGrid[N - row - 1][col] = tempCol[row];
        }
    }

    gameGrid = tempGrid; //applies all the changes
}

void moveTilesLeft(Grid& gameGrid) {
    Grid tempGrid(N, std::vector<int>(N, 0)); //temp grid to hold non-zeros

    for (int row = 0; row < N; row++) {
        std::vector<int> tempRow; //temp row to hold non-zeros in row
        for (int col = 0; col < N; col++) {
            if (gameGrid[row][col] != 0) {
                tempRow.push_back(gameGrid[row][col]); //adds non-zeros to tempRow
            }
        }
        mergeTiles(tempRow); //merge the tiles in the row 

        for (int col = 0; col < tempRow.size(); col++) { //replaces the tempGrid row with the merged tempRow
            tempGrid[row][col] = tempRow[col];
        }
    }

    gameGrid = tempGrid; //applies all the changes
}

void moveTilesRight(Grid& gameGrid) {
    Grid tempGrid(N, std::vector<int>(N, 0)); //temp grid to hold non-zeros

    for (int row = 0; row < N; row++) {
        std::vector<int> tempRow; //temp row to hold non-zeros in row
        for (int col = 0; col < N; col++) {
            if (gameGrid[row][N - col - 1] != 0) {
                tempRow.push_back(gameGrid[row][N - col - 1]); //adds non-zeros to tempRow, but in reverse (its right)
            }
        }
        mergeTiles(tempRow); //merge the tiles in the row

        for (int col = 0; col < tempRow.size(); col++) { //replaces the tempGrid row with the merged tempRow
            tempGrid[row][N - col - 1] = tempRow[col];
        }
    }

    gameGrid = tempGrid; //applies all the changes
}

void mergeTiles(std::vector<int>& row) {
    int i = 0; // Start index
    int j = 1; // Next index (i+1)

    while (j < row.size()) { // Loop through the row and merge adjacent tiles with same value
        if (row[i] == row[j] && row[i] != 0) { // If adjacent tiles have the same value AND not zero, merge
            row[i] *= 2; // Double the value of the current tile
            row[j] = 0;  // Set the value of the next tile to zero
            i = j + 1;   // Move the start index to the next element after the merged tiles
            j = i + 1;   // Move the next index to the element after the start index
        }
        else {
            if (row[i] == 0 && row[j] != 0) { // If the current tile is zero AND the next tile is not zero, swap
                std::swap(row[i], row[j]);    // Moves the non-zero tile towards the beginning of row
            }

            // Move to the next pair of elements in the row to compare
            i++;
            j++;
        }
    }
}

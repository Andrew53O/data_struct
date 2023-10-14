// Author: 洪理川 B113040056
// Date: Oct. 14  2023
// Purpose: Test if a knight can visit each positon of a chess board (using recursive)

#include <iostream>
#include <iomanip> // for setw
using namespace std;

// struct for a knightMove
struct knightMove
{
	int row;
	int column;
};

// global prototypes
void KnightChess(int tableSize);
bool knightTour(int row, int column, int move, int **array, int tableSize) ;

// declare array of possible knight moves
knightMove moves[8] = {
					{-2, 1}, 
					{-1, 2}, 
					{1, 2}, 
					{2, 1}, 
					{2, -1}, 
					{1, -2}, 
					{-1, -2}, 
					{-2, -1} 
					};

// Main function
int main(void) 
{
  cout << "When n = 1: " << endl;
	KnightChess(1);

  cout << "When n = 2: " << endl;
	KnightChess(2);

  cout << "When n = 3: " << endl;
	KnightChess(3);

  cout << "When n = 4: " << endl;
	KnightChess(4);

  cout << "When n = 5: " << endl;
	KnightChess(5);

  cout << "When n = 6: " << endl;
	KnightChess(6);

  return 0;
}

void KnightChess(int tableSize)
{

  // Create a chessboard array.
  int **array = new int*[tableSize];
  for (int i = 0; i < tableSize; i++) 
  {
    array[i] = new int[tableSize];
  }

  // Initialize the chessboard array to 0.
  for (int i = 0; i < tableSize; i++) 
  {
    for (int j = 0; j < tableSize; j++) 
    {
      array[i][j] = 0;
    }
  }

  // Start the knight's tour at the top left corner of the chessboard.
  int row = 0;
  int column = 0;
  int move = 1;

  // fixed value
	array[0][0] = move;

  // Call the recursive function to find a knight's tour.
  bool success = knightTour(row, column, move, array, tableSize);

  // If the function returned true, there is a knight's tour.
  if (success) 
  {
    // Print the knight's tour with formatting
    for (int i = 0; i < tableSize; i++) {
      for (int j = 0; j < tableSize; j++) {
        cout << setw(3) <<array[i][j] << " ";
      }
      cout << endl;
    }
  } 
  else 
  {
    cout << "No knight's tour." << endl;
  }

  // Free the chessboard array.
  for (int i = 0; i < tableSize; i++) 
  {
    delete[] array[i];
  }

  delete[] array;

  cout << endl;
}

// Recursive function to find a knight's tour
bool knightTour(int row, int column, int move, int **array, int tableSize) 
{
  // If the knight has visited all squares, the tour is complete.
  if (move == tableSize * tableSize) {
    return true;
  }

  // Check all possible moves for the knight.
  for (int i = 0; i < 8; i++) {
    int nextRow = row + moves[i].row;
    int nextColumn = column + moves[i].column;

    // If the move is valid and the knight has not visited the square before,
    // make the move and recursively call the function.
    if (nextRow >= 0 && nextRow < tableSize && nextColumn >= 0 && nextColumn < tableSize && array[nextRow][nextColumn] == 0) {
      array[nextRow][nextColumn] = move + 1;
      if (knightTour(nextRow, nextColumn, move + 1, array, tableSize)) {
        return true;
      }
      // If the move did not lead to a solution, backtrack.
      array[nextRow][nextColumn] = 0;
    }
  }

  // If no valid moves can be made, return false.
  return false;
}
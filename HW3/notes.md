
problem
1. when should i stop, and declare it is "no solution"
    because for example in 3 * 3 grid,
    it will have no solve, 
    so backtracting until back to starting position kah (?)


2. how to use 2d array as paramater 


To Do:

1. tambahin previousKmove > 8 di
// No solution case because it doesn't find any possible path from the starting point (after trying all moves)
			if (currentRow == 0 && currentColumn == 0)
			{
				cout << "No solution" << endl;
				break;
			}
2. 

atau pakek ini
			if (knightStack->TopNode == NULL)
			{
				cout << "No solution" << endl;
				break;
			}




change for new n by n array
1. n
2. array3
3. if(arrayFull(array3, 3))
4. int Kmove = knightPossibleMove(currentRow, currentColumn, previousKMove, array3, 3);
5. array3[currentRow][currentColumn] = step;
6. cout << array3[i][j] << " "; (di for loop display akhir)

7. bool arrayFull(int array[][3], int size)
arrayFull paramter soalnya 2d harus pakek yang belakang

8. // Global prototypes
bool arrayFull(int array[][3], int size);

9. int knightPossibleMove(int row, int column, int previousKMove,  int array[][5], int tableSize)

done!

1 ~ 7 
2~4 no solution


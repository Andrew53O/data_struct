
problem
1. when should i stop, and declare it is "no solution"
    because for example in 3 * 3 grid,
    it will have no solve, 
    so backtracting until back to starting position kah (?)


2. how to use 2d array as paramater 


To Do:

1. bikin if else, klo misal masuk ke baru, setting Kmove jadi 0 
2. 




10. ganti stack jadi 1 aja , tinggal replace "three"



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

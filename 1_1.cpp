// Author : �x�z�t B113040056
// Date   : 2023/09/11
// Purpose: To construct a NxN magic square(for odd N)

#include <iostream>
#include <cstdlib> // abs()
#include <iomanip> // setw() 

using namespace std;

// global prototypes 
void magicSquare(int N);

int main(void)
{
	// 1x1, 3x3, 5x5, 7x7, 9x9 magic squares
	for(int i = 1; i <= 9; i+=2)
	{
		magicSquare(i);
		cout << endl << endl;
	}
	
	return 0;
}

// Create a N*N magic squares
void magicSquare(int N)
{
	const int num = N;
	
	// Create a dynamic 2D array
    int** square = new int*[num];
    for (int i = 0; i < num; ++i) 
	{
        square[i] = new int[num];
    }

    // Initialize the array (set all elements to 0)
    for (int i = 0; i < num; ++i) 
	{
        for (int j = 0; j < num; ++j) 
		{
            square[i][j] = 0;
        }
    }
	
	// Initialize axes and insert 1 value
	int x_axis = 0;
	int y_axis = num / 2;
	
	square[x_axis][y_axis] = 1;

	int insertNum = 2; // starting value
	
	
	for (int i = 0; i < (num*num) - 1; i++)
	{
		// placed in position (i-1, j-1)
		x_axis = (x_axis - 1 + num) % num;
		y_axis = (y_axis - 1 + num) % num;
		
		// place position in (i+1, j)
		if (square[x_axis][y_axis] != 0)
		{
			// bring back to original position
			x_axis = (x_axis + 1 ) % num;
			y_axis = (y_axis + 1 ) % num;
			
			// finding empty position
			while (square[x_axis][y_axis] != 0)
			{
				x_axis = (x_axis + 1 ) % num;
			}
			
			square[x_axis][y_axis] = insertNum;
		}
		else
		{
			square[x_axis][y_axis] = insertNum;
		}
		
		insertNum++;
	}
	
	// display with formatting
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << setw(2) << square[i][j] << " ";
		}
		cout << endl;
	}
	
}





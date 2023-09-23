// Author : 洪理川 B113040056
// Date   : 2023/09/11
// Purpose: Print 1! to N! (N factorial), with dynamic array

#include <iostream>

using namespace std;

// global prototypes
void printFac(int N);

int main(void)
{
	// placeholder for input value
	int n;
 
	// Keep looping until break case
	while(true) 
	{
		// reading input
		cin >> n; 

		// terminate the loop
		if (n == 0)
			break;

		// call the function each loop
		printFac(n);
	}
	 
	return 0;
}

// print 1! to N! 
void printFac(int N)
{
 	// default array length, must be positive
	int lengthArray = 10;

	// declare a dynamic array 
	int *array  = new int[lengthArray];
	
 	// initialize array with 0
	for (int i = 0; i < lengthArray; i++)
	{
		array[i] = 0;
	}
	
	// insert default value
	array[0] = 1;

	// compute factorial from 1 to N!
	for (int i = 1; i <= N; i++)
	{
		// mutliply all element with i 
		for (int j = 0; j < lengthArray; j++)
		{
			array[j] = array[j] * i;
		}
		
		// check every number in the array
		for (int k = 0; k < lengthArray; k++)
		{
			if(array[k] >= 10)
			{
				// variable for exceeded value
				int more = array[k] / 10;
				
				// keep the ones
				array[k] = array[k] % 10;
				
				// check whether the length of the dynamic array
				if (k + 1 < lengthArray)
				{
					// insert the exceeded value 
					array[k + 1] += more;
				}
				else // make the length longer
				{
					// temporary placholder for old length 
					int oldLengthArray = lengthArray; 

					// make the length longer
					lengthArray = lengthArray * 2;

					// new dynamic array
				    int* newArray = new int[lengthArray];
				
					// initialize array with 0
					for (int i = 0; i < lengthArray; i++)
					{
						newArray[i] = 0;
					}
					
				    // Copy elements from the old array to the new array
				    for (int i = 0; i < oldLengthArray; i++) {
				        newArray[i] = array[i];
				    }
				
				    // Deallocate the old array
				    delete[] array;
				
				    // Update the pointer to the new array
				    array = newArray;
	
					// insert the exceeded value 
					array[k + 1] += more;
				}

			}
		}
		
		// placeholder of starting Index
		int startingIndex = 0;  

		// output the 1 to N number
		cout << i << "!=";
		
		// find the index of the first digit
		for (int l = lengthArray -1 ; l >= 0; l--)
		{
			// find the first nonzero
			if (array[l] != 0)
			{
				// set the index to the variable
				startingIndex = l;
				break;
			}
		}
		
		// Output the complete number
		for (int l = startingIndex; l >= 0; l--)
		{
			cout << array[l];
		}

		// New line for every number in N! 
		cout << endl;
		
	}

	// New line for every factorial
	cout << endl;
}

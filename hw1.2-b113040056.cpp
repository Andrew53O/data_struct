#include <iostream>

using namespace std;

// global prototypes
void printFac(int N);

int main(void)
{
 // placeholder for input value
	int n;
 
	while(true) 
	{
		cin >> n; // bisa pakek vector buat simpen valuenya baru bisa di print out
		
  // terminate the loop
		if (n == 0)
					break;

		printFac(n);

	}
	 
	return 0;
}

// print 1! to N! 
void printFac(int N)
{
 // default array length
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

 // output the default value
		cout << "1!=1" << endl;	

	for (int i = 2; i <= N; i++)
	{
		// mutliply all element with i 
		for (int j = 0; j < lengthArray; j++)
		{
			array[j] = array[j] * i;
		}
		
		for (int k = 0; k < lengthArray; k++)
		{
			
			if(array[k] >= 10)
			{
				// pass the value to front
				int more = array[k] / 10;
				
				array[k] = array[k] % 10;
				
				// check whether overflow or not
				if (k + 1 < lengthArray)
				{
					array[k + 1] += more;
				}
				else
				{
					// make 2 times dynamic array and copy the value
					int oldLengthArray = lengthArray;
					lengthArray = lengthArray * 2;
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

					cout << endl;
				
				    // Deallocate the old array
				    delete[] array;
				
				    // Update the pointer to the new array
				    array = newArray;
	
					// add the number
					array[k + 1] += more;
				}
			}
		}
		
		// output every loop

		bool findFirstNum = false;
		int startingIndex;  // placeholder of starting Index


		cout << i << "!=";
		
		// find the index of the first digit
		for (int l = lengthArray -1 ; l >= 0; l--)
		{
			
			if (array[l] != 0)
			{
				findFirstNum = true;
				startingIndex = l;
			}
				
		}
		
		// output the complete number
		for (int l = startingIndex; l >= 0; l--)
		{
			cout << array[l];

		}

		cout << endl;
		
	}
}

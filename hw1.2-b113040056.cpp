#include <iostream>

using namespace std;

void printFac(int N);

int main(void)
{
	int n = 1; 
	while(n != 0) 
	{
		cin >> n; // bisa pakek vector buat simpen valuenya baru bisa di print out
		
		printFac(n);
	}
	
	
	return 0;
}

void printFac(int N)
{
	int lengthArray = 10;
	// declare a dynamic array with size of 10 
	int *array  = new int[lengthArray];
	
	for (int i = 0; i < lengthArray; i++)
	{
		array[i] = 0;
	}
	
	// insert default value
	array[0] = 1;
	
	if (N > 0)
	{
		cout << "1!=1" << endl;	
	}
	
	
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
		
		
		
		cout << i << "!=";
		
		for (int l = lengthArray -1 ; l >= 0; l--)
		{
			if (array[l] != 0)
			{
				findFirstNum = true;
			}
			
			if (findFirstNum == true)
			{
				cout << array[l];
			}
		}
		cout << endl;
		
	}
	
	
}

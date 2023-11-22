// Author: 洪理川 B113040056
// Date: Nov. 11 2023
// Purpose: To compare the efficiency of five different sorting algorithms
#include <iostream>
#include <algorithm> // for sort()
#include <random>
#include <limits>
#include <stdlib.h> // for qsort()
#include <chrono>	// for chrono record the execution time
#include <iomanip>	// for setprecision()
#include <fstream> // for output input stream file

using namespace std;
using namespace std::chrono; // for chrono record time

// 5 types of sort
void selectionSort(int* array, int size);
void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
int partition(int arr[], int low, int high);
void radixsort(int array[], int size);
int compare(const void* num1, const void* num2); // for function paramater in qsort()


// function that wrap 5 types of the sorting
void count_selectionSort(int* array, int size, ofstream& outputFile);
void count_mergeSort(int* array, int size, ofstream& outputFile);
void count_radixSort(int* array, int size, ofstream& outputFile);
void count_qsort(int* array, int size, ofstream& outputFile);
void count_sort(int* array, int size, ofstream& outputFile);

// function that reset the array value with a copy of unsorted array
void resetArrayValue(int* sorted_array, int* unsorted_array, int size);

int main(void)
{
	ifstream inputFile; // delcare input stream

	inputFile.open("input500.txt"); // read selected file
	int cases; // n lines of random number
	inputFile >> cases;

	int* arr = new int[cases]; // array to save all input elements
	int* copy_arr = new int[cases]; // A copy of above array

	// inserting values to the 2 array
	for (int i = 0; i < cases; i++)
	{
		inputFile >> arr[i];
		copy_arr[i] = arr[i];
	}

	inputFile.close(); // close the file

	ofstream outputFile; // declare output stream

	// Sory array using Quick Sort 10 times 
	for (int i = 0; i < 10; i++)
	{
		count_radixSort(arr, cases, outputFile);

		resetArrayValue(arr, copy_arr, cases); // reset back to unsorted array

	}
	cout << endl;

	return 0;
}

// Reset array by copy the original value to the sorted array
void resetArrayValue(int* sorted_array, int* unsorted_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		sorted_array[i] = unsorted_array[i];
	}
}

// Wrapper of Selection Sort that will 
	// 1. Output to a File
	// 2. Count the time for the Selection Sort
void count_selectionSort(int* array, int size, ofstream& outputFile)
{
	outputFile.open("outputA.txt"); // open outputA file

	cout << "Selection Sort" << endl;
	outputFile << "Selection Sort" << endl; // output to the file

	auto start = high_resolution_clock::now(); // Start counting

	selectionSort(array, size); // selection sort

	auto stop = high_resolution_clock::now(); // stop counting

	long double duration = duration_cast<microseconds>(stop - start).count(); // calculate time
	duration *= 1e-6; // change to seconds
	cout << "Time : " << fixed << setprecision(6) << duration << " seconds" << endl;

	// output asceding sorted array to the file
	for (int i = 0; i < size; i++)
	{
		outputFile << array[i] << endl;
	}

	outputFile.close();
}

// Wrapper of Merge Sort that will 
	// 1. Output to a File
	// 2. Count the time for the Merge Sort
void count_mergeSort(int* array, int size, ofstream& outputFile)
{
	outputFile.open("outputB.txt"); // open outputB file

	cout << "Merge Sort" << endl;
	outputFile << "Merge Sort" << endl; // output to the file

	auto start = high_resolution_clock::now(); // Start counting

	mergeSort(array, 0, size - 1); // Merge Sort

	auto stop = high_resolution_clock::now(); // stop counting

	long double duration = duration_cast<microseconds>(stop - start).count(); // calculate time
	duration *= 1e-6; // change to seconds
	cout << "Time : " << fixed << setprecision(6) << duration << " seconds" << endl;

	// output asceding sorted array to the file
	for (int i = 0; i < size; i++)
	{
		outputFile << array[i] << endl;
	}

	outputFile.close();
}

// Wrapper of Radix Sort that will 
	// 1. Output to a File
	// 2. Count the time for the Radix Sort
void count_radixSort(int* array, int size, ofstream& outputFile)
{
	outputFile.open("outputC.txt"); // open outputC file

	cout << "Radix Sort" << endl;
	outputFile << "Radix Sort" << endl; // output to the file

	auto start = high_resolution_clock::now(); // Start counting

	radixsort(array, size - 1); // radix Sort

	auto stop = high_resolution_clock::now(); // stop counting

	long double duration = duration_cast<microseconds>(stop - start).count(); // calculate time
	duration *= 1e-6; // change to seconds
	cout << "Time : " << fixed << setprecision(6) << duration << " seconds" << endl;

	// output asceding sorted array to the file
	for (int i = 0; i < size; i++)
	{
		outputFile << array[i] << endl;
	}

	outputFile.close();
}

// Wrapper of C qsort() that will 
	// 1. Output to a File
	// 2. Count the time for the C qsort()
void count_qsort(int* array, int size, ofstream& outputFile)
{
	outputFile.open("outputD.txt"); // open outputD file

	cout << "C qsort()" << endl;
	outputFile << "C qsort()" << endl; // output to the file

	auto start = high_resolution_clock::now(); // Start counting

	qsort(array, size, sizeof(int), compare); // C qsort()

	auto stop = high_resolution_clock::now(); // stop counting

	long double duration = duration_cast<microseconds>(stop - start).count(); // calculate time
	duration *= 1e-6; // change to seconds
	cout << "Time : " << fixed << setprecision(6) << duration << " seconds" << endl;

	// output asceding sorted array to the file
	for (int i = 0; i < size; i++)
	{
		outputFile << array[i] << endl;
	}

	outputFile.close();

}

// Wrapper of C++ sort() that will 
	// 1. Output to a File
	// 2. Count the time for the C++ sort()
void count_sort(int* array, int size, ofstream& outputFile)
{
	outputFile.open("outputE.txt"); // open outputE file

	cout << "C++ Sort()" << endl;
	outputFile << "C++ Sort()" << endl; // output to the file

	auto start = high_resolution_clock::now(); // Start counting

	sort(array, array + size); // C++ Sort();

	auto stop = high_resolution_clock::now(); // stop counting

	long double duration = duration_cast<microseconds>(stop - start).count(); // calculate time
	duration *= 1e-6; // change to seconds
	cout << "Time : " << fixed << setprecision(6) << duration << " seconds" << endl;

	// output asceding sorted array to the file
	for (int i = 0; i < size; i++)
	{
		outputFile << array[i] << endl;
	}

	outputFile.close();
}

void selectionSort(int* array, int size)
{
	int i, j, min_i;

	// find minimum element and swap one by onee
	for (i = 0; i < size - 1; i++)
	{

		// Find the minimum index
		min_i = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_i])
				min_i = j;
		}

		// Swap with the minimum index if different
		if (min_i != i) // check if i min_i changed
			swap(array[min_i], array[i]);
	}
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

	// Create L ← A[p..q] and M ← A[q+1..r]
	int n1 = q - p + 1;
	int n2 = r - q;

	int* L = new int[n1];
	int* M = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2)
	{
		if (L[i] <= M[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = M[j];
		j++;
		k++;
	}
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// m is the point where the array is divided into two subarrays
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		// Merge the sorted subarrays
		merge(arr, l, m, r);
	}
}

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int *output = new int[size];
  int *count = new int[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

// qsort function argument, to sort ascending
int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
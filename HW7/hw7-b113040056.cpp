#include <iostream>
#include <algorithm> // for sort()
#include <random>
#include <limits>
#include <stdlib.h>  // for qsort()


using namespace std;

int random_number();

void selectionSort(int* array, int size);
void merge(int array[], int const left, int const mid,int const right);
void mergeSort(int array[], int const begin, int const end);

int partition(int arr[],int low,int high);
void quickSort(int arr[],int low,int high);

int main(void)
{
    int a[10] = {};

    for (int i = 0; i < 10; i++)
    {
        a[i] = random_number();
    }

    cout << "printing result" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }

    cout << endl << "abis sorting" << endl;

    //selectionSort(a, 10);
    //mergeSort(a, 0, 10 - 1);
    //quickSort(a, 0, 10 - 1);
    //qsort(a);
    sort(a, a + 10);


    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

int random_number()
{
    // Create a random number generator engine
    random_device rd;  // Use hardware entropy to seed the random number generator
    mt19937 gen(rd()); // Mersenne Twister 19937 generator

    int min_range = 0;
    int max_range = numeric_limits<int>::max();
    max_range = 20;
    cout << "min range" << min_range << endl;
    uniform_int_distribution<int> distribution(0, max_range);

    // Generate a random number
    int random_number = distribution(gen);

    return random_number;
}

void selectionSort(int* array, int size)
{
    int i, j, min_i;
    
    // find minimum element and swap one by onee
    for (i = 0; i < size - 1; i++) {

        // Find the minimum index
        min_i = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_i])
                min_i = j;
        }

        // Swap the 
        if (min_i!= i) // check if i min_i changed
            swap(array[min_i], array[i]);
    }
}


// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

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
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

int partition(int arr[],int low,int high)
{
  //choose the pivot
   
  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}
 
// The Quicksort function Implement
            
void quickSort(int arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot
     
    int pi=partition(arr,low,high);
     
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}
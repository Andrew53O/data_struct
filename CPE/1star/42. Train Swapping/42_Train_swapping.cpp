#include <iostream>
using namespace std;

int main(void)
{
    int n; cin >> n;
    while(n--)
    {
        int length, swap = 0; cin >> length;
        int array[length];
        for (int i = 0; i < length; i++)
            cin >> array[i];
        for (int i = 0; i < length -1; i++) // bubble sort
            for (int j = 0; j < length -1 - i; j++)
            {
                if (array[j] > array[j+1])
                {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    swap++;
                }
            }
        cout << "Optimal train swapping takes " << swap << " swaps." << endl;   
    }
    return 0;
}
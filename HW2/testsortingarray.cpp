#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    char arrs[] = {'}', '1', '2', ' ', ';', '[', 'a', 'd', 'c', 'A', 'B'};
    int i, j;

    // 
    for (i = 0; i < sizeof(arrs); i++)
    {
        for (j = i + 1; j < sizeof(arrs); j++)
        {
            if (arrs[i] > arrs[j])
            {
                char temp = arrs[i];
                arrs[i] = arrs[j];
                arrs[j] = temp; 
            }
        }

    }

    for (int k = 0; k < sizeof(arrs); k++)
    {
        cout << arrs[k] << " ";
    }

    cout << endl;

}
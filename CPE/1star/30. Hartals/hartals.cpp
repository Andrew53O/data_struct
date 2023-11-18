#include <iostream>

// Time spent ~ 1 hour
using namespace std;

int main(void)
{
    int TestCases;

    cin >> TestCases;

    while(TestCases--)
    {
        int nDays;
        int parties;
        cin >> nDays;
        cin >> parties;

        int* array = new int[parties]; // saves the party 
        bool* beenTo = new bool[nDays];

        for (int i = 0; i < nDays; i++)
        {
            beenTo[i] = false;
        }

        for (int i = 0; i < parties; i++)
        {
            cin >> array[i]; 
        }   

        int res = 0;
        for (int i = 0; i < parties; i++)
        {
            // runing n days
            for (int j = array[i]; j <= nDays; j += array[i])
            {
                                // tricky in here, since it tell us there will not be multiple of 7
                                // but that doesn't guarantee other number will not multiple of 7 

                                // need to j - 1, becuse it is array 
                if ((j % 7) != 6 && (j % 7) != 0 && beenTo[j - 1] == false ) 
                {
                    res++;
                    beenTo[j - 1] = true;
                }
                else{
                
                   // cout << "j -> " << j << endl;
                    //cout << beenTo[array[i]] << endl;
                }
                
            }
        }
        cout << res << endl;
        

    }

    return 0;
}
#include <iostream>

using namespace std;

int main(void)
{
    int n; 

    cin >> n;

    while(n--)
    {
        int a, b, c;

        cin >> a >> b >> c;

        char array[a][b];

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                cin >> array[i][j];
            }
        }
        cout << a << " " << b << " " << c << endl;
        for (int i = 0; i < c; i++)
        {
            int left, right; 
            cin >> left >> right;

            char startingChar = array[left][right];
            //cout << "startingchar->" << startingChar << endl;
            
            // find the leftmost peak position
            int templeft, tempright;

            int answer = 1;
            int minus = 1;
            while(true)
            {
                bool exit = false;
                templeft = left - minus; 
                tempright = right - minus; 

                if (templeft < 0 || tempright < 0)
                {
                    break;
                }
                else
                {

                    for (int col = templeft; col < templeft + answer + 2; col++)
                    {
                        if (templeft + answer + 2 > a)
                        {
                            exit = true;
                            break;
                        }

                        for (int row = tempright; row < tempright + answer + 2 ; row++)
                        {
                            if (tempright + answer + 2 > b)
                            {
                                exit = true;
                                break;
                            }
                            //cout << "row-> " << row << endl;
                            if (array[col][row] != startingChar)
                                exit = true;

                            //cout << array[col][row] << " ";
                            //cout << "col->" << col << " row->" << row; 
                        }
                        //cout << endl;
                    }
                }
                if (exit)
                    break;
                else
                {
                    //cout << "masuk" << endl;
                    //cout << "exit" << exit << endl;
                    answer+=2;
                    minus++;
                }
                
            }


            cout << answer << endl;
        }

    } 

    return 0;
}
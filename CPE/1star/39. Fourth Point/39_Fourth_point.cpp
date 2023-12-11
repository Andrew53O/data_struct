#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    float a1, a2, a3, a4, b1, b2, b3, b4;
    while(cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4)
    {   
        // find which 2 point are the same
        float sameX, sameY, diff1x, diff1y, diff2x, diff2y;
        if (a1 == a3 && b1 == b3)
        {
            sameX = a1; sameY = b1;
            diff1x = a2; diff1y = b2;
            diff2x = a4; diff2y = a4; 
        }
        else if (a2 == a3 && b2 == b3)
        {
            sameX = a2; sameY = b2;
            diff1x = a1; diff1y = b1;
            diff2x = a4; diff2y = b4; 
        }
        else if (a1 == a4 && b1 == b4)
        {
            sameX = a1; sameY = b1;
            diff1x = a2; diff1y = b2;
            diff2x = a3; diff2y = a3; 
        }
        else if (a2 == a4 && b2 == b4)
        {
            sameX = a2; sameY = b2;
            diff1x = a1; diff1y = b1;
            diff2x = a3; diff2y = a3; 
        }
        cout << fixed << setprecision(3)<< (diff1x + diff2x) - sameX << " ";
        cout << fixed << setprecision(3) << (diff1y + diff2y) - sameY << endl;
    }



    return 0;
}
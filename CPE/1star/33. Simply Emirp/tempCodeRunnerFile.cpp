#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkPrime(int x)
{
    if (x < 2)
        return false;

    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isEmirp(int x)
{
    // reverse number
    string temp = to_string(x);
    reverse(temp.begin(), temp.end());
    int reversedd = stoi(temp);
    
    if (x != reversedd)
    {
        if (checkPrime(reversedd))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;

}

int main(void)
{
    int n;
    while(cin >> n)
    {
        bool isPrime = false;

        isPrime = checkPrime(n);

        if (isPrime)
        {
            if(isEmirp(n))
            {
                cout << n << " is emirp." << endl;
            }
            else
            {
                cout << n << " is prime." << endl;
            }
            
        }
        else
            cout << n << " is not prime." << endl;
    }

    return 0;
}
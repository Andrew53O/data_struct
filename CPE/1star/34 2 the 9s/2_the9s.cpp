#include <iostream>
#include <string>
using namespace std;

int count(string s, int degree)
{
    int sum = 0;
	
    for (int i = 0; i < s.size(); i++)
    {
        sum += s.at(i) - '0';

    }   
    degree++;

    if (sum == 9)
    {
		return degree;
    }
    else if (sum < 9)
    {
        return 0;
    }
    else
    {
        return count(to_string(sum), degree);
    }
}


int main(void)
{
    string s;
    while(getline(cin, s) && s != "0")
    {
        int c = count(s, 0);
        if (c == 0)
        {
            cout << s << " is not a multiple of 9." << endl;
        }
        else
        {
        	cout << s << " is a multiple of 9 and has 9-degree " << c <<"." <<endl;
        }
    }

    

    return 0;
}
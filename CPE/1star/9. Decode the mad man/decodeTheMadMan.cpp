#include <iostream>
#include <string>

using namespace std;


int main(void)
{
    string s;
    
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        decodeIt(s[i]);
    }
    cout << s << endl;

    return 0;
}

// check dia alnum atau bukan , klo bukan masuk ke string yang ada capital

// 
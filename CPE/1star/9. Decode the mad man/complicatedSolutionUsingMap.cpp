#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

unordered_map<char, char> decoder = {
	{'e', 'q'}, {'r', 'w'}, {'t', 'e'}, {'y', 'r'}, {'u', 't'}, {'i', 'y'}, {'o', 'u'}, {'p', 'i'}, {'[','o'},{']','p'},
    
    // ASDFG Row
    {'d', 'a'}, {'f', 's'}, {'g', 'd'}, {'h', 'f'}, {'j', 'g'}, {'k', 'h'}, {'l', 'j'}, {';', 'k'},{'\'','l'},
    
    // ZXCVB Row
    {'c', 'z'}, {'v', 'x'}, {'b', 'c'}, {'n', 'v'}, {'m', 'b'}, {',','n'}, {'.','m'}
};

int main(void)
{
	string str; 
	while(getline(cin, str))
	{
		for (int i = 0; i < str.size(); i++)
	{
		auto it = decoder.find(tolower(str[i]));
		
		if (it != decoder.end())
		{
			cout << it-> second;
		}
		else
		{
			cout << str[i];
		}
	}
	cout << endl;
	}
	


	return 0;
}

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void)
{
	string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	
	string input;
	
	
	while(getline(cin, input))
	{
		string output = "";
		
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == ' ')
			{
				output += " ";
				continue;
			}
			
			input[i] = tolower(input[i]);
			
			int one = keyboard.find(input[i]);
			one-=2;
			if(one < 0)one += input.length(); // pinter
			output+=keyboard[one];
			
		}
		
		cout << output << endl;
	}

	
	return 0;
}

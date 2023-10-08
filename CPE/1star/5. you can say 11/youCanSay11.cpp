#include <iostream>
#include <string>


using namespace std;


int check(string s)
{
	int length= s.length();
	
	int odd = 0;
	int even = 0;
	
	for (int i = 0; i < length; i++)
	{
		if ( i % 2 == 0)
		{
			even += (s.at(i) - '0');
			
		}
		else
		{
			odd += (s.at(i) - '0' );
		}
	}
	
	return (abs(even - odd) % 11 == 0 );
}

int main(void)
{

	string s;
	
	while(true)
	{
		cin >> s;
		if (s == "0")
			break;
			
		check(s) ? cout << s << " is a multiple of 11." << endl : cout << s << " is not a multiple of 11." << endl;
		
	
	}


	return 0;
}
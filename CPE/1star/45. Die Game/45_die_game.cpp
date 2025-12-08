#include <iostream> 
// #include <bits/stdc++.h>
#include <string> 

using namespace std;


int main(void)
{	
	int n, index;  
	string s;
	

	
	while(cin >> n)
	{
		int top = 1;
		int right = 4;
		int left = 3;
		int bottom = 6;
		int front = 5;
		int back = 2;
		int temp;
	
		if (n == 0) break;
		
		// get where the dice is now
		for (int i = 0; i < n; i++)
		{
			cin >> s; 
			if (s == "north")
			{
				temp = top;
				top = front;
				front = bottom;
				bottom = back;
				back = temp;

			
			}
			else if (s == "south")
			{
				temp = top;
				top = back;
				back = bottom;
				bottom = front;
				front = temp;

			}
			else if (s == "east")
			{
				temp = top;
				top = left;
				left = bottom;
				bottom = right;
				right = temp;

				
			}
			else if (s == "west")
			{
				temp = top;
				top = right;
				right = bottom;
				bottom = left;
				left = temp;

			}
			
		}
			cout << top << endl;
	}
	

	return 0;
}
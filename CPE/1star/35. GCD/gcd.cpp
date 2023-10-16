#include <bits/stdc++.h>
using namespace std;


int GCD(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	else return GCD(b % a, a);

}

int main(void)
{
	int N;
	
	while(true)
	{
		cin >> N;
		if (N == 0) break;
		
		int	G=0;

		for(int i=1;i<N;i++)
		
		for(int j=i+1;j<=N;j++)
		
		{
		
		      G+=GCD(i,j);
		
		}
		
		cout << (int) G << endl;
	}
	


}
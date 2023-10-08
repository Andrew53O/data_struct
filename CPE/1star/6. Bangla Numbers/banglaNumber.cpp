#include <iostream>
#include <string>

using namespace std;

int bangla(unsigned long long int N)
{
	if(N/10000000)
	{
		bangla(N/10000000);
		
		N = N % 10000000;
		cout  << " kuti";
		
	}
	
	if (N > 99999)
	{	
		cout << " " << N/100000 << " lakh";
		N = N %  100000;
		
	}
	
	if (N > 999)
	{
		cout << " " << N/1000 << " hajar";
		N = N % 1000;
		
	}
	
	if (N > 99)
	{
		cout << " " << N/100 << " shata";
		N = N % 100;
	
	}
	
	if (N > 0)
		cout  << " " << N; 
	
	

}

int main(void)
{
	unsigned long long int n;
	int count = 1;
	
	while(cin >> n)
	{
		
		printf("%4d.", count++);
		
		
		if (n == 0)
		{
			printf(" 0\n");
			continue;
		}
		
		
		bangla(n);
		cout << endl;

		
	}

	return 0;
}
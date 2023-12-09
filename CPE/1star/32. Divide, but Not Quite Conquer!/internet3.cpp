#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int m,n;
	int data[100];
	while(cin>>n>>m)
	{
		if(m <=1 or n<m)
		{
			cout<<"Boring!"<<endl;
			continue;
		}

		int c=0;
		while(n%m==0 and n>=m)
		{
			data[c++]=n;
			n/=m;
		}
		data[c]=n;
		if(data[c]!=1 || c==0)
		{
			cout<<"Boring!"<<endl;
		}
		else
		{
			for(int i=0;i<=c;i++)
			{
				cout<<data[i];
				if (i != c)
					cout << " ";
				
			}
			cout<<endl;
		}
	}



}
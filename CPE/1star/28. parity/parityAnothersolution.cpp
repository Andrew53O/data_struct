#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<long long> v = {};


void constructV(vector <long long> &v)
{
	for(long long i = 1; i <= 2147483647; i*=2)
	{
		v.push_back(i);
	}
}

int parity(long long a, string &s)
{
	int temp_a = a;
	bool start = false;
	int count = 0; 
	
	int index = v.size() - 1;// largest index in vector
	while(index >= 0)
	{
		if(a - v[index] >=0)
		{
			count +=1;
			a -= v[index];
			s += "1";
			start = true; // start counting the 0's
		}	
		else if(start)
		{
			s += "0";
		}
		
		index--;
	}
	
	   if (s.empty()) {
        s = "0";
    }
	
	return count;
}

int main(void)
{
	constructV(v);
	int a;
	while(cin >> a)
	{
		if(a == 0) break;
		string binaryR = "";
		
		int result = parity(a, binaryR);
		
		cout << "The parity of " << binaryR << " is " << result << " (mod 2)." << endl;
	}
	
	return 0;
}
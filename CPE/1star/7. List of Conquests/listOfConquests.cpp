#include <iostream>
#include <vector>
#include <string>
#include <ios>
#include <limits>
#include <algorithm>
using namespace std;


struct Answer
{
	string country;
	int count = 0;
	
};

bool compareByCountry(const Answer &left, const Answer &right)
{
	return (left.country < right.country);
}

int main(void)
{
	vector <Answer> v;
	int n ;
	string temp, temp2;
	cin >> n;
	
	for (int i = 0; i < n;i++)
	{
		cin >> temp;
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, temp2);
		
		Answer t;
		t.country = temp;
		
		bool insideVector = false;
		 for (int j = 0; j < v.size(); j++)
		 {
		 	if(v[j].country == t.country)
		 	{
		 		v[j].count++;
		 		
		 		insideVector = true;
		 	}
		 }
		if (!insideVector)
		{
			t.count++;
			v.push_back(t);
		}
	}
	
	// sort 
	
	sort(v.begin(), v.end(), compareByCountry);
	
	for (int i = 0; i < n;i++)
	{
		cout << v[i].country << " " << v[i].count << endl;
    }
	
	return 0;
}
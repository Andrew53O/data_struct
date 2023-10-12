#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Alphabet
{
	char c;
	int count = 0;
};

bool compareCount(Alphabet a, Alphabet b)
{
	if (a.count == b.count)
	{
		return a.c < b.c ;
	}
	return a.count > b.count;
}


int main(void)
{
	Alphabet A[26];
	
	// initiliazite alphabet
	char alpha = 'A';
	for (int i = 0; i < 26; i++)
	{
		A[i].c = alpha;
		alpha++;
	}

	int n ;
	string s;	
	cin >> n;
	
	cin.ignore(10000, '\n');
	
	
	while(n--)
	{
		// cout << "helloj" << endl;
		getline(cin, s);
		
		for (int i = 0; i < s.size(); i++)
		{
			if ( toupper(s[i]) >= 65 && toupper(s[i]) <= 90 )
			{
				A[toupper(s[i]) - 65].count++;
			}
		}		
	}
	
	int elements = sizeof(A) / sizeof(A[0]);
	
	sort(A, A + elements, compareCount);
	
	cout.flush();
	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		if (A[i].count != 0)
		{
			cout << A[i].c << " " <<A[i].count << endl;
		
		}
		
	}
	
	return 0;
}

// email ke cpe klo soal ini selalu ga ada output, klo  ga ada cout
// coba tanya



//== 以上是自[瘋狂雲端]下載的資料 請自行剪貼到各檔中進行寫作
/*
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Alphabet
{
	char c;
	int count = 0;
};

bool compareCount(Alphabet a, Alphabet b)
{
	if (a.count == b.count)
	{
		return a.c < b.c ;
	}
	return a.count > b.count;
}


int main(void)
{
	Alphabet A[26];
	
	// initiliazite alphabet
	char alpha = 'A';
	for (int i = 0; i < 26; i++)
	{
		A[i].c = alpha;
		alpha++;
	}

	int n ;
	string s;	
	cin >> n;
	
	cin.ignore(10000, '\n');
	
	
	while(n--)
	{
		getline(cin, s);
		
		for (int i = 0; i < s.size(); i++)
		{
			if ( toupper(s[i]) >= 65 && toupper(s[i]) <= 90 )
			{
				A[toupper(s[i]) - 65].count++;
			}
		}		
	}
	
	int elements = sizeof(A) / sizeof(A[0]);
	
	sort(A, A + elements, compareCount);
	
	for (int i = 0; i < 26; i++)
	{
		if (A[i].count != 0)
		{
			cout << A[i].c << " " << A[i].count << endl;
		
		}
		
	}
	
	return 0;
}
//*/

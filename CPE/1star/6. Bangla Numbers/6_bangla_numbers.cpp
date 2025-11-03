#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int ARR[4] = {10000000, 100000, 1000, 100};
string SSS[4] = {"kuti", "lakh", "hajar", "shata"};

string build(long long int num, string& s)
{	
	int front, back; 
	string result; 
	if (num == 0) return "";
	if (num < 100) return  to_string(num);
	else if (num >= 10000000) {
        front = num / 10000000;
        back = num % 10000000;
        result = build(front, s) + " kuti";
        string tail = build(back, s);
        if (!tail.empty()) result += " " + tail;
        return result;
    }
    else if (num >= 100000) {
        front = num / 100000;
        back = num % 100000;
        result = build(front, s) + " lakh";
        string tail = build(back, s);
        if (!tail.empty()) result += " " + tail;
        return result;
    }
    else if (num >= 1000) {
        front = num / 1000;
        back = num % 1000;
        result = build(front, s) + " hajar";
        string tail = build(back, s);
        if (!tail.empty()) result += " " + tail;
        return result;
    }
    else if (num >= 100) {
        front = num / 100;
        back = num % 100;
        result = build(front, s) + " shata";
        string tail = build(back, s);
        if (!tail.empty()) result += " " + tail;
        return result;
    }

}

int main(void)
{
	long long int num;
	int c = 1; 
	while(cin >> num)
	{
		string res = ""; 
		string temp = "";
		
		if (num == 0)
			temp = "0";
		else
			temp = build(num, res);
		
		cout << setw(4) << c << ". " << temp << endl;
		c++;
	}
return 0;
}
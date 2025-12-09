#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // ignore the leftover newline

    map<string, int> mp;
    string line;

    for (int i = 0; i < n; i++) {
        getline(cin, line);     // read the whole line
        stringstream ss(line);

        string country, name;
        ss >> country;          // first word = country
        // the rest of the line is the name, but we ignore it

        mp[country]++;          // count the frequency
    }

    // map outputs automatically sorted by key (country)
    for (auto &p : mp) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

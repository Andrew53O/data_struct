#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mod;

bool cus(const int &a, const int &b)
{
    int ma = a % mod;
    int mb = b % mod;

    if (ma != mb)
        return ma < mb;

    bool aOdd = (a % 2 != 0);
    bool bOdd = (b % 2 != 0);

    // odd numbers first
    if (aOdd != bOdd)
        return aOdd;  // true means aOdd comes before bEven

    // both odd → descending
    if (aOdd && bOdd)
        return a > b;

    // both even → ascending
    return a < b;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        cout << N << " " << M << "\n";
        if (N == 0 && M == 0) break;

        mod = M;

        vector<int> v(N);
        for (int i = 0; i < N; i++) cin >> v[i];

        sort(v.begin(), v.end(), cus);

        for (int x : v) cout << x << "\n";
    }
    return 0;
}

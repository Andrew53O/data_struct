#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false), cin.tie(nullptr);
	int sequence[32], amount, divisor;
	while (cin >> sequence[0] >> divisor) {	
		if (divisor <= 1 || sequence[0] <= 1) {
			cout << "Boring!\n";
			continue;
		}
		amount = 0;
		while (!(sequence[amount] % divisor))
			sequence[amount + 1] = sequence[amount] / divisor, ++amount;
		if (sequence[amount] == 1)
			for (int i = 0; i <= amount; ++i)
				cout << (i ? " " : "") << sequence[i];
		else
			cout << "Boring!";
		cout << '\n';
	}
}
#include <iostream>
using namespace std;

int main() {
	int number, reverse = 0, remaining, mod = 0;
	cout << "input number to check: " << endl;
	cin >> number;
	remaining = number;
	while (remaining != 0) {
		mod = remaining % 10;
		reverse = (reverse * 10) + mod;
		remaining = remaining / 10;
	}
	if (number == reverse) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	return 0;
}

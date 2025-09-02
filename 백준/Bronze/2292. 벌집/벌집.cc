#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0;; i++) {
		if (N <= 1 + 3 * i * (i + 1)) {
			cout << i + 1 << endl;
			return 0;
		}
	}
}
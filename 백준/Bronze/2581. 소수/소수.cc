#include <iostream>

using namespace std;

int main() {

	int m, n;
	cin >> m >> n;
	int cnt = 0;
	int sum = 0;
	int min = 10001;

	for (int i = m; i <= n; i++) {
		for (int div = 1; div <= i; div++) {
			if (i % div == 0)
				cnt++;
		}
		if (cnt == 2) {
			sum += i;
			if (min > i)
				min = i;
		}
		cnt = 0;
	}

	if (sum == 0 && min == 10001) {
		cout << "-1";
	}
	else {
		cout << sum << endl;
		cout << min;
	}
}
/*셀프 넘버*/

#include <iostream>

using namespace std;

int d(int n) {
	int sum = n;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int arr[10001] = { 0 };
	int result;

	for (int i = 1; i < 10001; i++) {
		result = d(i);
		if (result < 10001)
			arr[result] = 1;
	}

	for (int k = 1; k < 10001; k++) {
		if (arr[k] != 1)
			cout << k << '\n';
	}
}
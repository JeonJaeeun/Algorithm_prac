
#include <iostream>

using namespace std;

int arr[41] = { 0 };

int fib (int n) {
	if (n == 1 || n == 2)
		return 1;

	else {
		return (fib(n - 1) + fib(n - 2));
	}
}

int main() {

	int n;
	cin >> n;

	int cnt = 0;

	arr[1] = arr[2] = 1;
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		cnt++;
	}
	cout << fib(n) << ' ' << cnt;
}
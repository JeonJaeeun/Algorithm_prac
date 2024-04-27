#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 1;
	for (int sum = 2; sum <= n; i++)
		sum += 6 * i;

	if (n == 1)
		cout << "1";

	else 
		cout << i;
}
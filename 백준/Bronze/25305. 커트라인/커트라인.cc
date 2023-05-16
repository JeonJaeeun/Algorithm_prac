/*커트라인*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int x[10000];

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	sort(x, x + n);

	cout << x[n - k];
}
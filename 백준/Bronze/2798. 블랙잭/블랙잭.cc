/*블랙잭*/

#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int num[100];
	int max = 0;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = 0;
				sum = num[i] + num[j] + num[k];
				if (sum <= m)
					if(max<sum)
						max = sum;
			}
		}
	}

	cout << max;
}
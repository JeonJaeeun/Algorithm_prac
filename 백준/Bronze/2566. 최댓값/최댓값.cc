//2566

#include <iostream>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num, n, m, max = 0; //숫자, 행 번호, 열 번호, 최댓값

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> num;
			if (num >= max) {
				max = num;
				n = i;
				m = j;
			}
		}
	}

	cout << max << '\n' << n << ' ' << m;
}
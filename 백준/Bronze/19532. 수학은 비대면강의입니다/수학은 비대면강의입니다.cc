//19532
/*
	1. 알아서 계산
	2. 식을 먼저 정리 -> 복잡
*/

#include <iostream>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if (a * i + b * j == c) {
				if (d* i + e * j == f) {
					cout << i << ' ' << j;
				}
			}
		}
	}
}
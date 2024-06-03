/*신나는 함수 실행*/

/*
	메모이제이션 사용 : 컴퓨터 프로그램이 동일한 계산을 반복해야 할 때,
				이전에 계산한 값을 메모리에 저장함으로 
				동일한 계산의 반복 수행을 제거하는 방식의 알고리즘
*/

#include <iostream>

using namespace std;

int tmp[21][21][21] = { 0, };

int w(int a, int b, int c) {

	//base condition
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	//메모이제이션
	if (tmp[a][b][c] != 0)
		return tmp[a][b][c];

	if (a < b && b < c) {
		tmp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return tmp[a][b][c];
	}

	else {
		tmp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		return tmp[a][b][c];
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		int res = w(a, b, c);

		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		cout << res << '\n';
	}
}
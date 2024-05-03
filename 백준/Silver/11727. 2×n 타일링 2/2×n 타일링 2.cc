#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v;
	// 1x2, 2x1, 2x2
	// 2x1: 1개, 2x2: 3개, 2x3: 5개, 2x4: 11개, 2x5: 21개 ..
	int n, res;
	cin >> n;

	// 0번째 부터 2번째까지는 직접 수 넣기
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);

	// 3번째부터 n번째 까지 동적 계획법 사용
	for (int i = 3; i <= n; i++) {
		int num;
		num = (v[i - 1] + v[i - 2] * 2) % 10007;
		v.push_back(num);
	}
	cout << v[n] << '\n';
}
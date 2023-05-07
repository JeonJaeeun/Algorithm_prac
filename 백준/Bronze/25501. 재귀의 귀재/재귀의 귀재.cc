/*재귀의 귀재*/

/*
	25501 -> 재귀 사용시 시간초과
	25501r -> for문으로 풀기
*/

#include <iostream>

using namespace std;

int main() {
	
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	string s;

	for (int i = 0; i < t; i++) {
		cin >> s;

		int cnt = 0;
		int left = 0;
		int right = s.length() - 1;
		bool flag = true;

		for (; left <= right; left++, right--) {

			cnt++;

			if (s[left] != s[right]) {
				flag = false;
				break;
			}
		}

		cout << (flag ? 1 : 0) << ' ';

		if (flag == true && s.length() % 2 == 0)
			cout << cnt + 1 << '\n';
		else
			cout << cnt << '\n';
	}
}
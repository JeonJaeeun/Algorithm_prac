#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	stack<pair<int,int>> s;
	int index;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		// 현재 탑보다 작은 탑은 다 pop(), 큰 탑이 나오면 index 출력 후 현재 탑 push
		while (!s.empty() && s.top().first < tmp) {
			s.pop();
		}

		if (s.empty()) 
			cout << 0 << " ";
		else
			cout << s.top().second << " ";
		s.push({ tmp,i + 1 });
	}
	
}
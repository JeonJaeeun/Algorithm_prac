/*듣보잡*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<string> s;
	string st;
	for (int i = 0; i < n; i++) {
		cin >> st;
		s.insert(st);
	}

	string input;
	int cnt = 0;

	vector<string> answer;

	for (int i = 0; i < m; i++) {
		cin >> input;
		if (s.count(input)) {
			cnt++;
			answer.push_back(input);
		}
	}

	sort(answer.begin(), answer.end());

	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << answer[i] << '\n';
	}
}
#include <iostream>
#include <set>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	set <string> s;
	string st1;
	for (int i = 0; i < n; i++) {
		cin >> st1;
		s.insert(st1);
	}

	string st2;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> st2;
		if (s.count(st2) == 1)
			cnt++;
	}
	cout << cnt;
}
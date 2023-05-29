#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	
	cin >> m;
	vector<int> answer(m);

	int input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		auto upper = upper_bound(v.begin(), v.end(), input);
		auto lower = lower_bound(v.begin(), v.end(), input);

		answer[i] = upper - lower;
	}

	for (auto n : answer)
		cout << n << ' ';
}
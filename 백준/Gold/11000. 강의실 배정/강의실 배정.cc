#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int arrayRoom(int n, vector<ci> lec) {
	priority_queue<int, vector<int>, greater<>> pq;

	pq.push(-1);

	for (int i = 0; i < n; i++) {
		if (lec[i].first >= pq.top()) {
			pq.pop();
		}
		pq.push(lec[i].second);
	}
	return pq.size();
}

int main() {
	int n;
	cin >> n;

	vector<ci> lec(n, ci(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> lec[i].first >> lec[i].second;
	}

	sort(lec.begin(), lec.end());

	cout << arrayRoom(n, lec) << '\n';

	return 0;
}
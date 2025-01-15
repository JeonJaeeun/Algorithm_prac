/* 선분 위의 점*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	// 1. 점 입력받기
	vector<int> spot(n);
	for (int i = 0; i < n; i++) {
		cin >> spot[i];
	}

	// 2. 점 정렬
	sort(spot.begin(), spot.end());

	// 3. 선분마다 점 체크: lower bound와 upper bound 이용
	int start, end;

	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		
		auto lower = lower_bound(spot.begin(), spot.end(), start);
		auto upper = upper_bound(spot.begin(), spot.end(), end);

		cout << (upper - lower) << "\n";
	}

	return 0;
}
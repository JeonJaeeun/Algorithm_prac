/*랜선 자르기*/

/*
	k: 이미 가지고 있는 랜선의 개수
	n: 필요한 랜선의 개수
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int k, n;
	cin >> k >> n;

	vector<long long> v(k);
	long long max_len = 0;

	// 1. 랜선의 길이 입력받고, 최대 길이 추적
	for (int i = 0; i < k; i++) {
		cin >> v[i];
		max_len = max(max_len, v[i]);
	}

	// 2. 최소, 최대, 중간길이 설정
	long long low = 1;
	long long high = max_len;
	long long result = 0; //가능한 최대 길이

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long count = 0;

		// 3. 각 랜선을 mid 길이로 잘랐을 때 얻을 수 있는 랜선 개수 합산
		for (int i = 0; i < k; i++) {
			count += v[i] / mid;
		}

		// 4. 만약 개수가 n개 이상이면? -> mid + 1 로 이동
		if (count >= n) {
			result = mid;
			low = mid + 1;
		}
		// 5. 만약 개수가 n개 이하면? -> mid - 1 로 이동
		else {
			high = mid - 1;
		}
	}

	cout << result << endl;
	return 0;
}
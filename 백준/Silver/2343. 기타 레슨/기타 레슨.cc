/* 기타 레슨 */

/*
	강의의 순서대로 녹화해야 하며,
	주어진 m개의 블루레이에 모든 강의를 나누어 녹화하되,
	블루레이의 크기를 최소화하는 문제
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> length(n);
	int max_length = 0;
	int total_length = 0;

	for (int i = 0; i < n; i++) {
		cin >> length[i];
		max_length = max(max_length, length[i]);
		total_length += length[i];
	}

	/*
		1. low의 기준: 가능한 최소 블루레이 크기
		-> 최소한 가장 긴 강의이 길이 이상
		2. high의 기준: 가능한 최대 블루레이 크기
		-> 블루레이의 개수를 1개로 줄인 경우 (강의의 총합)
	*/

	int low = max_length;
	int high = total_length;
	int result = high;

	while (low <= high) {
		int mid = (low + high) / 2; // 현재 블루레이 크기 후보
		int current_sum = 0; // 현재 블루레이에 담긴 강의 길이 합
		int cnt = 1; // 블루레이 개수

		// 블루레이 개수 계산
		for (int len : length) {
			if (current_sum + len > mid) {
				// 현재 강의를 추가할 수 없다면 새로운 블루레이 시작
				cnt++;
				current_sum = len;
			}
			else {
				current_sum += len;
			}
		}

		if (cnt <= m) {
			// m개 이하의 블루레이로 녹화 가능 -> 블루레이 개수 늘려야 한다 -> 블루레이의 크기를 줄여본다.
			result = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << result << endl;

	return 0;
}
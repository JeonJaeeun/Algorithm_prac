#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int n;
	cin >> n;

	vector<int> times(n);

	// 입력 받기
	for (int i = 0; i < n; i++) {
		cin >> times[i];
	}

	// 작은 수부터 정렬
	sort(times.begin(), times.end());

	// 순서대로 중복해서 저장
	int tmp_sum = 0;
	int final_sum = 0;

	for (int i = 0; i < n; i++) {
		tmp_sum += times[i];
		final_sum += tmp_sum;
	}

	cout << final_sum;
}
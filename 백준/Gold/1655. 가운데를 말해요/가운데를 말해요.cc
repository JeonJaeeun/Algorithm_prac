#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	// 1. heap 사용 -> priority queue 정의
	priority_queue<int> left; // 최대힙
	priority_queue<int, vector<int>, greater<int>> right; // 최소힙

	// 2. 배열 입력받기
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		// 3. left와 right에 따로 저장
		// 3-1. left가 비어있거나, 중앙값보다 작으면 left.push
		if (left.empty() || x <= left.top())
			left.push(x);
		else
			right.push(x);

		// 4. 군형 맞추기 (왼쪽과 오른쪽이 같거나, 왼쪽이 오른쪽보다 1 크거나)
		// 4-1. 왼쪽 초과 (왼쪽 > 오른쪽 + 1)
		if (left.size() > right.size() + 1) {
			right.push(left.top());
			left.pop();
		}
		// 4-2. 오른쪽 초과 (왼쪽 < 오른쪽)
		else if (left.size() < right.size()) {
			left.push(right.top());
			right.pop();
		}

		// 5. 중앙값 출력
		cout << left.top() << "\n";
	}
}
/* 숨바꼭질 */
/*
	최단시간을 구해야 함 -> BFS (너비 우선 탐색) 사용
	BFS: 시작점에서 목표 지점까지의 최단 거리를 탐색하는 데 효율적
		- 시작점에서 시작
		- 큐에서 현재 위치와 경과 시간을 꺼낸다
		- 현재 위치가 동생의 위치와 같다면 경과 시간을 출력하고 종료
		- 그렇지 않으면 현재 위치에서 이동할 수 있는 세 가지 경우를 큐에 추가한다
			- X - 1
			- X + 1
			- 2 * X
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findShortesTime(int n, int k) {
	const int MAX = 100000; //최대 범위
	vector<bool> visited(MAX + 1, false); //방문 여부 확인
	queue<pair<int, int>> q; //pair(현재 위치, 시간)

	q.push({ n,0 }); //시작점 추가
	visited[n] = true;

	while (!q.empty()) {
		int current = q.front().first;
		int time = q.front().second;
		q.pop();

		//동생을 찾으면 시간 반환
		if (current == k) return time;

		//이동할 수 있는 세가지 경우
		if (current - 1 >= 0 && !visited[current - 1]) {
			q.push({ current - 1, time + 1 });
			visited[current - 1] = true;
		}
		if (current + 1 <= MAX && !visited[current + 1]) {
			q.push({ current + 1,time + 1 });
			visited[current + 1] = true;
		}
		if (current * 2 <= MAX && !visited[current * 2]) {
			q.push({ current * 2,time + 1 });
			visited[current * 2] = true;
		}
	}

	return -1;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << findShortesTime(n, k) << endl;
	return 0;
}
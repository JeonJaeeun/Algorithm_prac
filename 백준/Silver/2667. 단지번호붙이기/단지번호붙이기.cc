/* 단지 번호 붙이기 */
/*
	연결된 집의 모임을 단지로 정의 -> 단지에 번호를 붙임
	BFS 사용 -> Queue 사용
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;

//상하좌우 이동을 위한 방향 배열
int dx[4] = { -1, 1, 0, 0 }; //x 방향의 변화량 (상, 하, 좌, 우)
int dy[4] = { 0, 0, -1, 1 }; //y 방향의 변화량 (상, 하, 좌, 우)

int N;

// BFS 함수
int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	int house_cnt = 0; //현재 단지 내 집의 수

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		house_cnt++;

		//상하좌우 탐색
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			//지도 범위를 벗어나지 않고, 방문하지 않았으며, 집이 있는 경우
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == 1) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
	return house_cnt;
}

int main() {
	
	cin >> N;

	map.resize(N, vector<int>(N));
	visited.resize(N, vector < bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	vector<int> complexes; //각 단지의 집 개수를 저장할 벡터

	//지도를 순회하며 단지를 찾음
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//방문하지 않은 집 발견
			if (!visited[i][j] && map[i][j] == 1) {
				int house_cnt = bfs(i, j);
				complexes.push_back(house_cnt);
			}
		}
	}
	sort(complexes.begin(), complexes.end());

	cout << complexes.size() << "\n"; //총 단지 수
	for(int cnt : complexes) {
		cout << cnt << "\n";
	}

	return 0;
}
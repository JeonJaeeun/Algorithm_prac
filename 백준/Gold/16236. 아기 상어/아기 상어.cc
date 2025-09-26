#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n;
vector<vector<int>> space;

int sx, sy;
int sharkSize = 2;

vector<vector<bool>> visited;
vector<vector<int>> dist;
vector<tuple<int, int, int>> fishList;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			// 범위 밖이거나,
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			// 방문 했거나, 자신의 크기보다 큰 물고기 크기이면
			if (visited[nx][ny] || space[nx][ny] > sharkSize) continue;

			visited[nx][ny] = true;
			dist[nx][ny] = dist[cx][cy] + 1; // 이동
			q.push({ nx,ny });

			// 먹이 후보 저장
			if (space[nx][ny] > 0 && space[nx][ny] < sharkSize) {
				fishList.push_back({ dist[nx][ny],nx,ny });
			}
		}
	}
}

int main() {
	cin >> n;

	// 공간 입력
	space.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];
		}
	}

	// 아기 상어, 물고기 좌표
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (space[i][j] == 9) {
				sx = i;
				sy = j;
				space[i][j] = 0;
			}
		}
	}

	int time = 0;
	int eat = 0;

	while (true) {
		visited.assign(n, vector<bool>(n, false));
		dist.assign(n, vector<int>(n, 0));
		
		fishList.clear();

		bfs(sx, sy);

		if (fishList.empty()) break;

		sort(fishList.begin(), fishList.end());
		int d, fx, fy;
		tie(d, fx, fy) = fishList[0];

		// 이동하고 먹기
		time += d;
		eat++;
		space[fx][fy] = 0;
		sx = fx;
		sy = fy;

		if (eat == sharkSize) {
			sharkSize++;
			eat = 0;
		}
	}

	cout << time << endl;

}
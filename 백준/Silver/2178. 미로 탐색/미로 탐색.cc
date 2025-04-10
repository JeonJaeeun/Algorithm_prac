#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> maze;
vector<vector<bool>> visited;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		// 지금 큐에서 꺼낸 현재 좌표
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			// 다음 탐색할 좌표 
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			// 범위 밖이면 skip
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			// 벽 또는 이미 방문한 곳이면 skip
			if (maze[nx][ny] == 0 || visited[nx][ny]) continue;

			// 방문 처리 및 거리 업데이트
			visited[nx][ny] = true;
			maze[nx][ny] = maze[cx][cy] + 1; // 거리 갱신
			q.push({ nx,ny });
		}
	}
}

int main() {
	
	cin >> n >> m;

	maze.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m, false));


	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			maze[i][j] = line[j] - '0';
		}
	}
	
	bfs(0, 0);

	cout << maze[n - 1][m - 1] << endl;
}
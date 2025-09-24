#include <iostream>
#include <vector>
#include <algorithm>
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
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			// 다음 좌표가 범위 안에 존재하고, 
			// 방문하지 않았고 다음 좌표가 1이라면,
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (!visited[nx][ny] && maze[nx][ny] == 1) {
					maze[nx][ny] = maze[cx][cy] + 1;
					q.push({ nx,ny });
				}
			}
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

	cout << maze[n-1][m-1] << endl;
}
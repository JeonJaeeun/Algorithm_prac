#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> map;

vector<pair<int, int>> virus;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int maxSafe = 0;

// 바이러스 퍼뜨리기
void bfs(vector<vector<int>>& tmpMap) {
	queue<pair<int, int>> q;
	for (auto v : virus) {
		q.push(v);
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (tmpMap[nx][ny] == 0) {
					tmpMap[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}
	}

	int safe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmpMap[i][j] == 0) {
				safe++;
			}
		}
	}

	maxSafe = max(maxSafe, safe);
}

// 일단 벽 3개 세우고,
void makeWall(int idx, int cnt) {
	if (cnt == 3) {
		vector<vector<int>> tmpMap = map;
		bfs(tmpMap);
		return;
	}
	for (int i = idx; i < n * m; i++) {
		int x = i / m;
		int y = i % m;
			if (map[x][y] == 0) {
				map[x][y] = 1;
				makeWall(i + 1, cnt + 1);
				map[x][y] = 0;
			
		}
	}
}

int main() {
	cin >> n >> m;

	map.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	makeWall(0, 0);

	cout << maxSafe << endl;

}
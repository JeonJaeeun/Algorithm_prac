#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> farm;

int m, n, k;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int sx, int sy) {
	queue<pair<int,int>> q;
	visited[sx][sy] = true;
	q.push({ sx,sy });

	while (!q.empty()) {
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (farm[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {

		// n 세로, m 가로
		cin >> m >> n >> k;

		int bugNum = 0;

		visited.assign(n, vector<bool>(m, false));
		farm.assign(n, vector<int>(m, 0));

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			farm[b][a] = 1;
		}

		

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && farm[i][j]) {
					bugNum++;
					bfs(i, j);
				}
			}
		}

		cout << bugNum << endl;
	}
}
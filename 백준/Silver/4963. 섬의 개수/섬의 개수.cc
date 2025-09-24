#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> island;
vector<vector<bool>> visited;
int islandNum;

int w, h;

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;

	visited[sx][sy] = true;
	q.push({ sx,sy });
		
	while (!q.empty()) {
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();

		for (int d = 0; d < 8; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (visited[nx][ny]) continue;
			if (island[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {

		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		islandNum = 0;

		island.assign(h, vector<int>(w));
		visited.assign(h, vector<bool>(w, false));

		vector<pair<int, int>> land;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> island[i][j];
			}
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && island[i][j]) {
					islandNum++;
					bfs(i, j);
				}
			}
		}

		cout << islandNum << endl;
	}
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> pic;

int n, m;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int maxW = 0;
int w = 0;

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	visited[sx][sy] = true;
	q.push({ sx,sy });
	int w = 0;

	while(!q.empty()) {
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();
		w++;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (pic[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			
			q.push({ nx,ny });
			
		}
	}

	if (w >= maxW) {
		maxW = w;
	}
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	visited.assign(n, vector<bool>(m, false));
	pic.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pic[i][j];
		}
	}

	int picNum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && pic[i][j] == 1) {
				picNum++;
				
				bfs(i, j);
			}
		}
	}
	
	cout << picNum << endl;
	cout << maxW << endl;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000;

vector<vector<int>> box;
vector<vector<bool>> visited;
vector<vector<int>> time;

int m, n;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

// 다중 시작점
void bfs(vector<pair<int,int>> starts) {
	queue<pair<int, int>> q;
	for (auto s : starts) {
		int sx = s.first;
		int sy = s.second;

		visited[sx][sy] = true;
		time[sx][sy] = 0;
		q.push({ sx,sy });
	}

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
			if (box[nx][ny] == -1) continue;

			visited[nx][ny] = true;
			time[nx][ny] = time[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;

	box.assign(n, vector<int>(m));
	visited.assign(n, vector<bool>(m, false));
	time.assign(n, vector<int>(m, 0));

	vector<pair<int, int>> tomato;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				tomato.push_back({ i,j });
			}
		}
	}

	bfs(tomato);

	int maxNum = 0;
	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && box[i][j] == 0) {
				flag = true;
			}
			if (time[i][j] >= maxNum)
				maxNum = time[i][j];
		}
	}
	if (flag) {
		cout << "-1" << endl;
	}
	else {
		cout << maxNum << endl;

	}
}
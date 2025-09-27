#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> mp;
vector<vector<int>> dist;

vector<pair<int,int>> passList;
int foundDist;

vector<pair<int, int>> start;
vector<pair<int, int>> goal;
vector<vector<int>> passenger_idx;
vector<bool> donePassenger;

int n, m, fuel;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void bfsCandidate(int sx, int sy) {

	passList.clear();
	foundDist = -1;

	dist.assign(n, vector<int>(n, -1));
	queue<pair<int, int>> q;
	dist[sx][sy] = 0;
	q.push({ sx,sy });

	//시작 칸에 승객이 있는지 먼저 확인 (거리 0)
	int pidx_start = passenger_idx[sx][sy];
	if (pidx_start != -1 && !donePassenger[pidx_start]) {
		foundDist = 0;
		passList.push_back({ sx,sy });
	}

	while(!q.empty()) {
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위이내가 아니면
			if (dist[nx][ny] != -1) continue; // 방문했다면
			if (mp[nx][ny] == 1) continue; // 벽을 만나면

			dist[nx][ny] = dist[x][y] + 1;

			int pidx = passenger_idx[nx][ny];
			if (pidx != -1 && !donePassenger[pidx]) {
				// 최초발견이면
			// 출발지의 승객들을 만나는 최단거리 후보 PassList에 저장, 최단 거리도 foundDist에 저장
				if (foundDist == -1) {
					foundDist = dist[nx][ny];
					passList.push_back({ nx,ny });
				}
				// 같은 선상의 최단거리이면
				else if (dist[nx][ny] == foundDist) {
					passList.push_back({ nx,ny });
				}
			}

			q.push({ nx,ny });
		}
	}
}

int bfsToGoal(int sx, int sy, int gx, int gy) {
	dist.assign(n, vector<int>(n, -1));
	queue<pair<int, int>> q;
	dist[sx][sy] = 0;
	q.push({ sx,sy });

	while (!q.empty()) {
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();

		if (x == gx && y == gy) return dist[x][y];

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (mp[nx][ny] == 1) continue;
			if (dist[nx][ny] != -1) continue;

			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	return -1;
}

int main() {

	int sx = -1;
	int sy = -1;

	cin >> n >> m >> fuel;

	mp.assign(n, vector<int>(n, 0));
	passenger_idx.assign(n, vector<int>(n, -1));
	donePassenger.assign(m, false);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}

	cin >> sx >> sy;
	
	sx -= 1;
	sy -= 1;

	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		start.push_back({ a-1,b-1 });
		goal.push_back({ c-1,d-1 });
		passenger_idx[a - 1][b - 1] = i;
	}

	int taxi_x = sx;
	int taxi_y = sy;
	int remaining = m; // 남아있는 승객 수

	while (remaining > 0) {

		bfsCandidate(taxi_x, taxi_y);

		if (passList.empty()) {
			cout << -1 << endl;
			return 0;
		}

		sort(passList.begin(), passList.end());
		int pick_x = passList[0].first;
		int pick_y = passList[0].second;
		int pick_idx = passenger_idx[pick_x][pick_y];

		int distToPassenger = dist[pick_x][pick_y];
		if (fuel < distToPassenger) {
			cout << -1 << endl;
			return 0;
		}
		fuel -= distToPassenger;
		taxi_x = pick_x;
		taxi_y = pick_y;

		int gx = goal[pick_idx].first;
		int gy = goal[pick_idx].second;

		int distToGaol = bfsToGoal(taxi_x, taxi_y, gx, gy);
		if (distToGaol == -1 || fuel < distToGaol) {
			cout << -1 << endl;
			return 0;
		}
		fuel -= distToGaol;
		fuel += distToGaol * 2;
		donePassenger[pick_idx] = true;
		passenger_idx[start[pick_idx].first][start[pick_idx].second] = -1;

		taxi_x = gx;
		taxi_y = gy;
		remaining--;
	}

	cout << fuel << endl;
	return 0;
}
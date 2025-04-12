#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m, fuel;
vector<vector<int>> space;

int tx, ty;
vector<pair<int, int>> start;
vector<pair<int, int>> goal;

vector<vector<bool>> visited;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

vector<vector<int>> dist;
vector<tuple<int, int, int>> peopleList;

int distToGoal = 0;
int finalFuel = 0;

// 목적지까지 가는 최단거리 구하기
void bfsToGoal(int px, int py, int gx, int gy) {

	visited.assign(n, vector<bool>(n, false));
	dist.assign(n, vector<int>(n, 0));

	queue<pair<int, int>> q;
	q.push({ px,py });
	visited[px][py] = true;


	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (cx == gx && cy == gy) {
			distToGoal = dist[cx][cy];
			return;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] || space[nx][ny] == 1) continue;

			visited[nx][ny] = true;
			dist[nx][ny] = dist[cx][cy] + 1;
			q.push({ nx,ny });
		}
	}
	distToGoal = -1;
}

// 승객까지 가는 최단거리 후보 구하기
void bfsToPassengers(int tx, int ty) {

	visited.assign(n, vector<bool>(n, false));
	dist.assign(n, vector<int>(n, 0));

	queue<pair<int, int>> q;
	q.push({ tx,ty });
	visited[tx][ty] = true;

	for (int i = 0; i < m; i++) {
		if (start[i].first == tx && start[i].second == ty) {
			peopleList.push_back({ 0,tx,ty });
		}
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] || space[nx][ny] == 1) continue;

			visited[nx][ny] = true;
			dist[nx][ny] = dist[cx][cy] + 1;
			q.push({ nx,ny });

			// nx, ny가 출발지라면, peopleList에 저장
			for (int i = 0; i < start.size(); i++) {
				// 태웠던 손님 또 태우지 않도록
				if (start[i].first == -1 && start[i].second == -1) continue;

				if (nx == start[i].first && ny == start[i].second) {
					peopleList.push_back({ dist[nx][ny],nx,ny });
				}
			}
		}
	}
}

/*
	bfs에서 현재위치에서 각 승객까지 최단 거리를 구하고, peopleList에 저장 - okay
	손님 선택 fuel-=최단거리
	한 후 그 손님에 맞는 end 선택하여 거리 구함
	fuel-이동거리 -> 만약 음수라면 종료 아니라면 이동거리*2 더해줌
	다시 bfs 반복
*/

int main() {
	cin >> n >> m >> fuel;

	space.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];
		}
	}

	cin >> tx >> ty;
	tx--;
	ty--;

	start.resize(m);
	goal.resize(m);

	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		start[i] = { a - 1,b - 1 };
		goal[i] = { c - 1,d - 1 };
	}

	int cnt = 0;

	while (true) {
		
		peopleList.clear();

		bfsToPassengers(tx, ty);

		if (peopleList.empty()) {
			finalFuel = -1;
			break;
		}

		sort(peopleList.begin(), peopleList.end());
		int d, px, py;
		tie(d, px, py) = peopleList[0];

		fuel -= d;

		if (fuel < 0) {
			finalFuel = -1;
			break;
		}

		// 태운 손님 인덱스 찾기
		int passengerIdx = -1;
		for (int i = 0; i < m; i++) {
			if (start[i].first == px && start[i].second == py) {
				passengerIdx = i;
				break;
			}
		}
		int gx = goal[passengerIdx].first;
		int gy = goal[passengerIdx].second;

		bfsToGoal(px, py,gx,gy);

		if (distToGoal == -1 || fuel < distToGoal) {
			finalFuel = -1;
			break;
		}

		fuel += distToGoal;

		// 택시 위치 갱신
		tx = goal[passengerIdx].first;
		ty = goal[passengerIdx].second;

		// 손님 태운 표시
		start[passengerIdx] = { -1,-1 };
		goal[passengerIdx] = { -1,-1 };

		distToGoal = 0;
		
		cnt++;
		if (cnt == m) {
			finalFuel = fuel;
			break;
		}
	}

	cout << finalFuel << endl;
}
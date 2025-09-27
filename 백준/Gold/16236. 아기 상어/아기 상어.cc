#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> mp;
vector<vector<int>> dist;
vector<pair<int, int>> fishList;
int foundDist = -1;

int n;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int sharkSize = 2;
int eaten = 0;
int totalTime = 0;

// 현재 상어 위치에서 BFS를 돌려 도달 가능한 모든 칸까지의 최단 거리
void eatFish(int sx, int sy) {

	// fishList 초기화
	fishList.clear();
	foundDist = -1;

	vector<vector<int>> dist(n, vector<int>(n, -1));

	queue<pair<int, int>> q;
	
	q.push({ sx,sy });
	dist[sx][sy] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] != -1) continue; // 방문 했으면 skip
			if (mp[nx][ny] > sharkSize) continue;

			dist[nx][ny] = dist[x][y] + 1;

			// 먹이 후보 -> 필요한 값은 새로운 탐색 시작점이 되는 좌표이므로 
			// fishList.push_back({nx,ny});
			// 최단 이동 거리 (최소거리여야함) -> 누적 합이 정답이 되므로 
			// foundDist = dist[nx][ny];

			if (mp[nx][ny] != 0 && mp[nx][ny] < sharkSize) {
				if (foundDist == -1) {
					// 최초발견이면
					foundDist = dist[nx][ny];
					fishList.push_back({ nx,ny });
				}
				else if (dist[nx][ny] == foundDist) {
					// 같은 선상에서 발견되면
					fishList.push_back({ nx,ny });
				}
				// 만약 dist[nx][ny] > foundDist 이면 더 멀기 때문에 무시
			}

			if (foundDist == -1 || dist[nx][ny] <= foundDist) {
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	int sx, sy;

	mp.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 9) {
				sx = i;
				sy = j;
				mp[i][j] = 0;
			}
		}
	}

	// while문을 돌려 fishList의 후보가 없으면 먹을 물고기가 없으므로 break;
	// 근데 아기상어가 어느 위치로 갈지 결정되면 fishList를 비워야해 그리고 다시 시작점 기준으로 bfs를 돌려야해.
	// 근데 bfs를 돌리고 어떤게 최단거리인지 어케 알지?
	// sort(fishList.begin(), fishList.end()); 를 하고 fishLIST[0]을 시작점으로 다시 둬야하나.?

	while (1) {
		eatFish(sx, sy);

		// 먹을 물고기 없으면
		if (fishList.empty()) break;

		sort(fishList.begin(), fishList.end());

		int tx = fishList[0].first;
		int ty = fishList[0].second;

		// 이동 및 상태 갱신
		totalTime += foundDist; // foundDist는 bfs에서 찾은 최소거리
		mp[tx][ty] = 0; // 물고기 먹음
		sx = tx;
		sy = ty;

		eaten++;
		if (eaten == sharkSize) {
			sharkSize++;
			eaten = 0;
		}
	}

	cout << totalTime << endl;
}
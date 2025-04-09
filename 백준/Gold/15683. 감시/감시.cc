#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<vector<int>> room;

// cctv 정보
struct CCTV {
	int x, y, type;
};

vector<CCTV> cctvs;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

vector<vector<vector<int>>> cctvDirs = {
	{},
	{{0},{1},{2},{3}},
	{{0,2},{1,3}},
	{{0,1},{1,2},{2,3},{0,3}},
	{{0,1,2},{1,2,3},{0,1,3},{0,2,3}},
	{{0,1,2,3}}
};

int minBlind = 1e9;

void watch(int x, int y, int dir, vector<vector<int>>& tmp) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
		if (tmp[nx][ny] == 6) break;
		if (tmp[nx][ny] == 0) tmp[nx][ny] = -1;

		nx += dx[dir];
		ny += dy[dir];
	}
}

void dfs(int cnt, vector<vector<int>> tmp) {

	int blind = 0;

	if (cnt == cctvs.size()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == 0) {
					blind++;
				}
			}
		}
		minBlind = min(minBlind, blind);
		return;
	}

	int x = cctvs[cnt].x;
	int y = cctvs[cnt].y;
	int type = cctvs[cnt].type;

	for (auto dirs : cctvDirs[type]) {
		// room  복사본
		vector<vector<int>> copied = tmp;

		for (int d : dirs) {
			watch(x, y, d, copied);
		}

		dfs(cnt + 1, copied);
	}
}

int main() {

	cin >> n >> m;

	// 방 정보 입력
	room.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}

	// cctv 정보 입력받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (room[i][j] >= 1 && room[i][j] <= 5) {
				cctvs.push_back({ i,j,room[i][j] });
			}
		}
	}

	dfs(0, room);

	cout << minBlind << endl;
}
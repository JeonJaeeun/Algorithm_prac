#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> mp;

vector<vector<int>> time;

vector<pair<int, int>> viruses;
vector<pair<int, int>> selected;

int n, m;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int minTime = 1e9;

void spreadVirus(vector<pair<int,int>> selected) {
	
	//거리가 0인지 초기화 0인지 모르니까 -1로 초기화
	time.assign(n, vector<int>(n, -1));
	vector<vector<int>> tmp = mp;

	queue<pair<int, int>> q;

	for (auto s : selected) {
		q.push(s);
		int sx = s.first;
		int sy = s.second;
		time[sx][sy] = 0;
	}

	while (!q.empty()) {
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (tmp[nx][ny] == 1) continue;
			if (time[nx][ny] != -1) continue;

			time[nx][ny] = time[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	int localMax = 0;

	// 최대 시간 체크
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mp[i][j] == 0) {
				if (time[i][j] == -1) return;
				localMax = max(localMax, time[i][j]);
			}
		}
	}

	minTime = min(minTime, localMax);
}

// 바이러스 m개 고르는 함수 - dfs 활용
void pickVirus (int start, int depth) {
	
	if (depth == m) {
		spreadVirus(selected);
		return;
	}

	for (int i = start; i < viruses.size(); i++) {
		int x = viruses[i].first;
		int y = viruses[i].second;

		selected.push_back({ x,y });
		pickVirus(i + 1, depth + 1);
		selected.pop_back();
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	mp.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 2) {
				viruses.push_back({ i,j });
			}
		}
	}

	pickVirus(0, 0);
	
	if (minTime == (int)1e9) cout << -1 << endl;
	else
		cout << minTime << endl;
}
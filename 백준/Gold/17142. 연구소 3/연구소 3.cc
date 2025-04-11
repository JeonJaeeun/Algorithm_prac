#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> space;
vector<pair<int, int>> virus;
vector<pair<int, int>> selected;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int answer = 1e9;

void bfs(const vector<pair<int, int>>& selectedVirus) {
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (auto& s : selectedVirus) {
        int x = s.first, y = s.second;
        dist[x][y] = 0;
        q.push({ x, y });
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int cx = cur.first, cy = cur.second;
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (space[nx][ny] != 1 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[cx][cy] + 1;
                    q.push({ nx, ny });
                }
            }
        }
    }

    int maxTime = 0;
    bool valid = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (space[i][j] == 0) {
                if (dist[i][j] == -1) {
                    valid = false;
                    break;
                }
                maxTime = max(maxTime, dist[i][j]);
            }
        }
        if (!valid) break;
    }

    if (valid) {
        answer = min(answer, maxTime);
    }
}


// DFS를 통해 M개의 바이러스 조합 선택 (선택된 바이러스는 selected에 저장됨)
void pickVirus(int idx, int cnt) {
    if (cnt == m) {
        bfs(selected);
        return;
    }
    for (int i = idx; i < virus.size(); i++) {
        selected.push_back(virus[i]);
        pickVirus(i + 1, cnt + 1);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    space.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> space[i][j];
            // 바이러스 위치 (2)만 별도로 저장 (빈 칸 0, 벽 1)
            if (space[i][j] == 2)
                virus.push_back({ i, j });
        }
    }

    pickVirus(0, 0);
    cout << (answer == 1e9 ? -1 : answer) << "\n";
    return 0;
}

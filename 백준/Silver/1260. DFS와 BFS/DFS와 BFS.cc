#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
	visited[node] = true;
	cout << node << ' ';
	for (int nxt : graph[node]) {
		if (!visited[nxt]) dfs(nxt);
	}
}

void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int nxt : graph[cur]) {
			if (!visited[nxt]) {
				visited[nxt] = true;
				q.push(nxt);
			}
		}
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 정점, 간선, 탐색 시작할 정점의 번호
	int n, m, v;
	cin >> n >> m >> v;

	graph.assign(n + 1, {});

	// 간선이 연결하는 두 정점의 번호 (m개의 줄)
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// "작은 번호부터" 방문하기 위해 각 인접 리스트 정렬
	for (int i = 1; i <= n; ++i) {
		sort(graph[i].begin(), graph[i].end());
	}

	visited.assign(n + 1, false);
	dfs(v);
	cout << '\n';

	visited.assign(n + 1, false);
	bfs(v);
	cout << '\n';
}
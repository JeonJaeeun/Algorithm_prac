#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int computer;
vector<vector<int>> graph;
vector<bool> visited;

int virus = 0;

void bfs(int start) {
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int g : graph[x]) {
			
			if (visited[g]) continue;
			
			visited[g] = true;
			virus++;
			q.push(g);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> computer;

	int num;
	cin >> num;

	graph.assign(computer + 1, {});
	visited.assign(computer + 1, false);

	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);

	cout << virus << endl;
}
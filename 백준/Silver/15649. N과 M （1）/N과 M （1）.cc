/*N과 M (1)*/

#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool visited[10];

void dfs(int depth) {
	
	//탈출 조건
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			arr[depth] = i;
			visited[i] = 1;
			dfs(depth + 1);
			visited[i] = 0;
		}
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	dfs(0);
}
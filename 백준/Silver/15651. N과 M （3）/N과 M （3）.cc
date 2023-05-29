/*N과 M (3)*/

#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool visited[10];

void dfs(int depth) {
	
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
			visited[i] = true;
			arr[depth] = i;
			dfs(depth + 1);
			visited[i] = false;
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	dfs(0);
}
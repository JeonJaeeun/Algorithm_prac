/*N과 M (4)*/

#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool visited[10];

void dfs(int depth, int num) {

	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = num; i <= n; i++) {
		visited[i] = true;
		arr[depth] = i;
		dfs(depth + 1, i);
		visited[i] = false;
		num += 1;
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	dfs(0, 1);
}
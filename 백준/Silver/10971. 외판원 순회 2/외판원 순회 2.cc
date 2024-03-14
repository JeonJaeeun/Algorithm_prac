#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

void backtracking(int n, int cnt, int cur_city, int cost) {
	if (cost >= ans) {
		return;
	}
	if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
		//출발 도시(0)로 다시 돌아올 수 있는지 확인
		if (matrix[cur_city][0] != 0) {
			ans = min(ans, cost + matrix[cur_city][0]);
		}
		return;
	}
	for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
		if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
			visited[i] = true;
			backtracking(n, cnt + 1, i, cost + matrix[cur_city][i]);
			visited[i] = false;
		}
	}
}

// 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
int solution(const int n, const vector<vector<int>>& cost) {
	visited.assign(n, false);
	matrix = cost;

	//연산
	visited[0] = true;
	backtracking(n, 1, 0, 0);

	return ans;
}

int main() {
	int n;
	vector<vector<int>> cost;
	int answer;

	//입력
	cin >> n;
	cost.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	answer = solution(n, cost);

	//출력
	cout << answer;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> W;
vector<int> V;

vector<vector<int>> dp;

// dfs 시간초과 -> dp 이용
int solve(int idx, int curW) {

	// 종료 조건
	if (curW > K) return -1e9; // 무게초과 -> 불가능
	if (idx == N) return 0; // 모든 물건 둘러봄 -> 종료

	int &ret = dp[idx][curW]; // 참조사용 -> 바로 반영
	if (ret != -1) return ret; // 메모이제이션

	// 선택1 : 안담기
	ret = solve(idx + 1, curW);

	// 선택2 : 담기
	if (curW + W[idx] <= K) {
		ret = max(ret, V[idx] + solve(idx + 1, curW + W[idx]));
	}


	return ret;
}

int main() {

	cin >> N >> K;

	W.resize(N);
	V.resize(N);

	// weight, value 따로 저장
	for (int i = 0; i < N; i++) {
		cin >> W[i] >> V[i];
	}

	// dp 초기화
	dp.assign(N, vector<int>(K + 1, -1));

	cout << solve(0, 0) << endl;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int N;
	cin >> N;

	// 전체 그리드 입력받기
	vector<vector<char>> grid(N, vector<char>(N, 0));
	
	// head, heart 따로 저장하기
	pair<int, int> head;
	pair<int, int> heart;
	bool headFound = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == '*' && !headFound) {
				head = { i,j };
				headFound = true;
			}
		}
	}

	heart = { head.first + 1,head.second };

	// 심장 위치 출력
	cout << heart.first + 1 << " " << heart.second + 1 << endl;

	int hx = heart.first;
	int hy = heart.second;

	// 왼쪽 팔 수
	int leftarm = 0;
	for (int i = hy - 1; i >= 0; i--) {
		if (grid[hx][i] == '*') {
			leftarm++;
		}
	}

	// 오른쪽 팔 수
	int rightarm = 0;
	for (int i = hy + 1; i < N; i++) {
		if (grid[hx][i] == '*') {
			rightarm++;
		}
	}

	// 허리 길이
	int waist = 0;
	for (int i = hx + 1; i < N; i++) {
		if (grid[i][hy] == '*') {
			waist++;
		}
	}
	
	// 허리 좌표 구하기
	int wx = hx + waist - 1;
	int wy = hy;

	// 왼쪽 다리
	int leftleg = 0;
	for (int i = wx + 1; i < N; i++) {
		if (grid[i][wy-1] == '*') {
			leftleg++;
		}
	}

	// 오른쪽 다리
	int rightleg = 0;
	for (int i = wx + 1; i < N; i++) {
		if (grid[i][wy+1] == '*') {
			rightleg++;
		}
	}

	cout << leftarm << " " << rightarm << " " << waist << " ";
	cout << leftleg << " " << rightleg << "\n";
}
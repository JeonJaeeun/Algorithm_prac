//2579

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int total = 0; //계단의 개수
	cin >> total;

	//dp를 total크기로 초기화해주어야 함
	dp.resize(total);

	vector<int> stairs;

	int input;

	for (int i = 0; i < total; i++) {
		cin >> input;
		stairs.push_back(input);
	}

	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = max((stairs[0] + stairs[2]), stairs[1] + stairs[2]);
	
	for (int i = 3; i < total; i++) {
		dp[i] = max((dp[i - 2] + stairs[i]), (dp[i - 3] + stairs[i - 1] + stairs[i]));
	}

	cout << dp[total - 1];
}
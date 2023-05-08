//1965

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int box = 0;
	cin >> box;

	vector<int> boxSize;
	vector<int> dp;

	dp.resize(box, 1);

	for (int i = 0; i < box; i++) {
		int num;
		cin >> num;
		boxSize.push_back(num);
	}


	for (int i = 1; i < box; i++) {
		for (int j = 0; j < i; j++) {
			if (boxSize[i] > boxSize[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int boxMax = 0;
	for (int i = 0; i < box; i++) {
		boxMax = max(boxMax, dp[i]);
	}
	cout << boxMax;
}
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int k, string& table) {
	vector<int> people, burgers; //사람과 햄버거의 위치를 저장할 벡터
	vector<bool> eaten(n, false);

	//사람과 햄버거의 위치를 벡터에 저장
	for (int i = 0; i < n; i++) {
		if (table[i] == 'P') {
			people.push_back(i);
		}
		else if (table[i] == 'H') {
			burgers.push_back(i);
		}
	}

	int ans = 0; // 먹을 수 있는 사람

	//사람마다 햄버거를 찾음
	for (int p : people) {
		for (int i = 0; i < burgers.size(); i++) {
			// 햄버거를 먹을 수 있고, 아직 먹히지 않았으면
			if (!eaten[burgers[i]] && abs(p - burgers[i]) <= k) {
				eaten[burgers[i]] = true;
				ans++;
				break;
			}
		}
	}
	return ans;
}

int main() {
	
	int n, k;
	cin >> n >> k;

	string table;
	cin >> table;

	cout << solution(n, k, table);
}
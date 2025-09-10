#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;

	string bomb;
	cin >> bomb;

	vector<char> result;

	for (char c : s) {
		// s에서 하나씩 가져와 result 뒤에 붙인다.
		result.push_back(c);
		
		// bomb과 같다고 가정
		bool isBomb = true; 

		// 붙인 직후 result 뒤쪽 = bomb 인지 확인
		if (result.size() >= bomb.size()) {
			for (int i = 0; i < bomb.size(); i++) {
				// bomb과 하나라도 맞지 않으면 isBomb = false
				if (result[result.size() - bomb.size() + i] != bomb[i]) {
					isBomb = false;
					break;
				}
			}
			// bomb와 같으면 bomb의 size만큼 pop_back
			if (isBomb) {
				for (int i = 0; i < bomb.size(); i++) {
					result.pop_back();
				}
			}
		}
	}
	if (result.empty()) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
		}
	}
}
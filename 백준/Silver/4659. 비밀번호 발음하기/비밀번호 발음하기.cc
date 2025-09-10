#include <iostream>

using namespace std;

int main() {
	while (1) {
		string s;
		cin >> s;

		// 종료 조건
		if (s == "end") {
			break;
		}
		bool vowelExist = false;
		int consonantCnt = 0; // 자음 카운트
		int vowelCnt = 0; // 모음 카운트
		char prev = 0;

		bool checkComplete = false;

		for (char c : s) {
			// 조건 1

			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				vowelExist = true;
			}

			// 조건 2
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				vowelCnt++;
				consonantCnt = 0;
			}
			else {
				consonantCnt++;
				vowelCnt = 0;
			}

			// 조건 2 검사
			if (vowelCnt == 3 || consonantCnt == 3) {
				cout << "<" << s << "> is not acceptable." << endl;
				checkComplete = true;
				break;
			}

			// 조건 3
			if (prev == c && c != 'e' && c != 'o') {
				cout << "<" << s << "> is not acceptable." << endl;
				checkComplete = true;
				break;
			}
			prev = c;
		}
		// 조건 1 검사
		if (!vowelExist && !checkComplete) {
			cout << "<" << s << "> is not acceptable." << endl;
			checkComplete = true;
		}
		if(!checkComplete) {
			cout << "<" << s << "> is acceptable." << endl;
		}
	}
}
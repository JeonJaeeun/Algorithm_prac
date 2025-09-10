#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;

	// A-Z 카운트
	vector<int> cnt(26, 0);
	
	for (char c : s) {
		char C = toupper(c);

		int idx = C - 'A';
		cnt[idx]++;
	}

	// 최댓값 찾기
	int mx = 0;
	for (int x : cnt) {
		if (x > mx)
			mx = x;
	}

	// 최댓값을 가진 알파벳이 몇 개인지 세기
	int howMany = 0;
	int idx = -1;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] == mx) {
			howMany++;
			idx = i; // 마지막으로 만난 인덱스 저장
		}
	}

	if (howMany > 1) cout << "?\n";
	else cout << static_cast<char>('A' + idx) << "\n";
}
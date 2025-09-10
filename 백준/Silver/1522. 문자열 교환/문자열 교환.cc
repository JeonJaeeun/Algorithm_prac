#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string tmp, s;
	cin >> tmp;

	int cntA = 0;

	for (char t : tmp) {
		if (t == 'a') {
			cntA++;
		}
	}

	s = tmp + tmp;

	int minB = 1001;

	int range = s.size() - cntA;
	for (int i = 0; i < range; i++) {
		int cntB = 0;
		string part = s.substr(i, cntA);
		
		for (char p : part) {
			if (p == 'b') {
				cntB++;
			}
		}
		minB = min(minB, cntB);
	}

	cout << minB << endl;
}
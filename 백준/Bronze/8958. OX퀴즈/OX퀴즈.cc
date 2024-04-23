/*OX퀴즈*/

#include <iostream>

using namespace std;

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		int sum, cnt;
		sum = cnt = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O') {
				cnt++;
				sum += cnt;
			}
			else
				cnt = 0;
		}
		cout << sum << '\n';
	}

}
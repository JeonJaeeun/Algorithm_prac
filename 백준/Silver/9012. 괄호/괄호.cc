//9012

#include <iostream>
#include <stack>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t > 0) {
		t--;
		stack<char> st;

		string input;
		cin >> input;
		bool flag = true;

		for (int i = 0; i < input.length(); i++) {

			//'('가 나오면 push
			if (input[i] == '(') {

				st.push(input[i]);
			}

			else if (input[i] == ')'){
				if (st.empty()) {
					cout << "NO" << '\n';
					flag = false;
					break;
				}
				st.pop();
			}
		}

		if (flag == true) {
			if (!st.empty()) {
				cout << "NO" << '\n';
			}
			else {
				cout << "YES" << '\n';
			}
		}
	}
}
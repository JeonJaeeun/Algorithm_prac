//4949

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	while (1) {

		getline(cin, str);

		if (str == ".")
			break;

		stack<char> balance;
		bool flag = false;

		for (int i = 0; i < str.length(); i++) {

			if (str[i] == '(' || str[i] == '[') {
				balance.push(str[i]);
			}

			else if (str[i] == ')') {
				if (!balance.empty() && balance.top() == '(') {
					balance.pop();
				}
				else  {
					flag = true;
					break;
				}
			}

			else if (str[i] == ']') {
				if (!balance.empty() && balance.top() == '[') {
					balance.pop();
				}
				else {
					flag = true;
					break;
				}
			}
		}

		if (balance.empty() && flag == false) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
}
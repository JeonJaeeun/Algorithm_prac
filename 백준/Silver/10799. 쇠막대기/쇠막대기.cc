#include <iostream>
#include <stack>

using namespace std;

int solution(string str) {
	stack<char> st;
	int answer = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push('(');
		}
		else {
			st.pop();
			if (str[i - 1] == '(') {
				answer += st.size();
			}
			else {
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	string str;
	cin >> str;

	int answer = solution(str);
	cout << answer;

	return 0;
}
/*10798*/
/*
	문자열로 받기

*/

#include <iostream>
#include <string>

using namespace std;

char c[16][5];

int main() {

	string s; //문자열
	for (int i = 0; i < 5; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) { //문자열의 길이만큼 저장
			c[j][i] = s[j];
		}
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (c[i][j] == NULL)
				continue;
			cout << c[i][j];
		}
	}
}
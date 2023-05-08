/*단어 정렬*/

#include <iostream>
#include <algorithm>

using namespace std;

string word[20000];

//조건 순 정렬해주는 함수
int cmp(string a, string b) {
	//두 문자열의 길이가 같으면 사전 순 정렬
	if (a.length() == b.length())
		return a < b;
	//두 문자열의 길이가 다르다면 길이가 짧은 순부터 정렬
	else
		return a.length() < b.length();
}

int main() {

	int n;
	cin >> n;

	int s;

	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	//cmp의 반환값에 맞게 정렬이 동작
	sort(word, word + n, cmp);

	for (int i = 0; i < n; i++) {
		//중복된 경우 한번만 출력하기
		if (word[i] == word[i - 1])
			continue;
		cout << word[i] << "\n";
	}
}
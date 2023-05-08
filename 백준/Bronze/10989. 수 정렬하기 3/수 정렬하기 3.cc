//10989

#include <iostream>

#define MAX 100000

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[MAX + 1]{ 0, }; //arr 0으로 초기화

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num]++; //arr에 num 자리에 숫자의 갯수 넣기
	}

	for (int i = 1; i < MAX; i++) {
		if (arr[i] == 0)
			continue; //arr[i] 자리에 0이면 continue
		for (int j = 0; j < arr[i]; j++) //각 숫자의 개수만큼 출력
			cout << i << '\n';
	}
}
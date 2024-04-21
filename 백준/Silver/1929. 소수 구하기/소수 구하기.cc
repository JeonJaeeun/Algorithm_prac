#include <iostream>

using namespace std;

#define MAX 1000000

int a[MAX + 1]{ 0, };

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;

	cin >> m >> n;

	//배열 생성, 초기화
	for (int i = 2; i <= n; i++) {
		a[i] = i;
	}

	//m부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다
	// 이미 지워진 수는 건너뛴다
	for (int i = 2; i*i <= n; i++) {
		if (a[i] == 0) continue; //이미 지워진 수라면 건너뛰기

		//이미 지워진 숫자가 아니라면, 그 배수부터 출발하여, 
		//가능한 모든 숫자 지우기
		for (int j = i * i; j <= n; j += i) {
			a[j] = 0;
		}
	}

	//m부터 시작하여 남아있는 수를 출력
	for (int i = m; i <= n; i++) {
		if (a[i] != 0)
			cout << a[i] << '\n';
	}
	return 0;
}
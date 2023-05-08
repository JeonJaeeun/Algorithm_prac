/*좌표 압축*/

/*
	a vector에 원본 vector 저장
	b vector = a vector copy
	b vector 오름차순 정렬 후 erase, unique 활용해서 중복 제거
	lower_bound: 찾으려는 key 값보다 같거나 큰 숫자가 
			배열 몇 번째에서 처음 등장하는지 찾기 위해 사용
	iterator it 변수에 저장한 후 시작 주소값을 빼주며 반환
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> a(n); //처음 벡터

	int num;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> b(a); //a 벡터를 복사한 벡터
	sort(b.begin(), b.end()); //오름차순 정렬

	//중복되는 숫자 제거
	b.erase(unique(b.begin(), b.end()), b.end());

	for (int i = 0; i < n; i++) {

		//i번째 요소값의 위치 it
		auto it = lower_bound(b.begin(), b.end(), a[i]);

		cout << it - b.begin() << ' ';
	}
}
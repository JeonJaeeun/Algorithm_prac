//18870

/*
	lower_bound
		찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> vA;
	vector<int> vB(n);

	int tmp;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vA.push_back(tmp);
		vB[i] = vA[i]; //copy
	}

	sort(vB.begin(), vB.end());

	vB.erase(unique(vB.begin(), vB.end()), vB.end()); //중복제거

	for (int i = 0; i < n; i++) {
		//검색된 인덱스 값에서 초기 위치를 빼주기
		auto it = lower_bound(vB.begin(), vB.end(), vA[i]); 
		cout << it - vB.begin() << " ";
	}
}
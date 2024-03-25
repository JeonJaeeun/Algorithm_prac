#include <iostream>

using namespace std;

int abbre(int R, int r) {
	for (int i = r; i > 0; i--) {
		if (r % i == 0)
			if (R % i == 0) {
				return i;
			}
	}
}

int main(){

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;//링의 개수
	cin >> n;

	int R;
	cin >> R;
	int r, div;

	for (int i = 0; i < n-1; i++) {
		cin >> r;
		//약분
		div = abbre(R, r);
		cout << R / div << "/" << r / div << '\n';
		div = 0;
	}
}
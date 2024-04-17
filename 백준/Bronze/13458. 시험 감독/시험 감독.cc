#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int B, C;
	cin >> B >> C;

	//시험장 최대 1,000,000 * 응시자 수 최대 1,000,000 = 1,000,000,000,000
	long long ans = N;

	for (int i = 0; i < N; i++) {
		int count = arr[i] - B;
		if (count <= 0) {
			continue;
		}
		ans += count / C;
		if (count % C > 0) {
			ans++;
		}
	}
	cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int p;
	cin >> p;
	
	while (p > 0) {
		int t;
		cin >> t;

		vector<int> h;
		int cnt = 0;

		for (int i = 0; i < 20; i++) {
			int tmp;
			cin >> tmp;

			if (h.empty()) h.push_back(tmp);

			else {

				for (int j = 0; j < h.size(); j++) {
					if (h[j] > tmp) {
						cnt++;
					}
				}
				h.push_back(tmp);
				sort(h.begin(), h.end());
			}
		}
		cout << t << " " << cnt << "\n";

		p--;

	}
}
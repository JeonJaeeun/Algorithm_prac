#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	vector<int> block(w);

	for (int i = 0; i < w; i++) {
		cin >> block[i];
	}

	vector<int> max_left(w);
	vector<int> max_right(w);

	max_left[0] = block[0];
	max_right[w-1] = block[w - 1];

	for (int i = 1; i < w; i++) {
		max_left[i] = max(max_left[i - 1], block[i]);
	}

	for (int i = w - 2; i >= 0; i--) {
		max_right[i] = max(max_right[i + 1], block[i]);
	}

	int water = 0;

	for (int i = 0; i < w; i++) {
		if (min(max_left[i], max_right[i]) >= block[i]) {
			int h = min(max_left[i], max_right[i]) - block[i];
			if (h > 0) water += h;
		}
	}

	cout << water << "\n";
}
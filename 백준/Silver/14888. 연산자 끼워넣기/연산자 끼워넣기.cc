/*연산자 끼워넣기*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> num;
vector<int> expression;

int max_value = -INF;
int min_value = INF;

void calc(int cnt, int sum) {

	int new_sum = 0;

	if (cnt == num.size() - 1) {
		max_value = max(max_value, sum);
		min_value = min(min_value, sum);
		return;
	}


	for (int i = 0; i < 4; i++) {
		if (expression[i] > 0) {
			expression[i]--;

			switch (i) {
			case 0:
				new_sum = sum + num[cnt + 1];
				break;
			case 1:
				new_sum = sum - num[cnt + 1];
				break;
			case 2:
				new_sum = sum * num[cnt + 1];
				break;
			case 3:
				new_sum = sum / num[cnt + 1];
				break;
			}

			calc(cnt + 1, new_sum);
			expression[i]++;
		}
	}
}

int main() {

	int n;
	cin >> n;

	num.resize(n);
	expression.resize(4);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> expression[i];
	}

	calc(0, num[0]);
	cout << max_value << endl;
	cout << min_value;
}
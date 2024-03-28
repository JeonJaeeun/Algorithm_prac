#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	int n1, n2, n3; //n1이 가장 큰 수, n3가 가장 작은 수
	cin >> a >> b >> c;

	if (a > b) {
		if (a > c) {
			n1 = a;
			if (b > c) {
				n2 = b;
				n3 = c;
			}
			else {
				n2 = c;
				n3 = b;
			}
		}
		else {
			n1 = c;
			n2 = a;
			n3 = b;
		}
	}
	else { //b>=a
		if (b > c) {
			n1 = b;
			if (a > c) {
				n2 = a;
				n3 = c;
			}
			else {
				n2 = c;
				n3 = a;
			}
		}
		else {
			n1 = c;
			n2 = b;
			n3 = a;
		}
	}

	if (n1 == n2 && n1== n3 && n2==n3) {
		int r = 10000 + n1 * 1000;
		cout << r;
	}
	else if (n1 != n2 && n1 != n3 && n2 != n3) {
		int r = n1 * 100;
		cout << r;
	}
	else {
		if (n1 = n2) {
			int r = 1000 + n1 * 100;
			cout << r;
		}
		else if (n1 = n3) {
			int r = 1000 + n1 * 100;
			cout << r;
		}
		else {
			int r = 1000 + n2 * 100;
			cout << r;
		}
	}
}
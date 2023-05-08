/*나이순 정렬*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}
int main() {

	int n;
	cin >> n;

	int age;
	string name;

	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		v.push_back({ age,name });
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}
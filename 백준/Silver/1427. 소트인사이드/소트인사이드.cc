/*소트인사이드*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	string st;
	cin >> st;
	
	sort(st.begin(), st.end(), greater<char>());

	cout << st;
}
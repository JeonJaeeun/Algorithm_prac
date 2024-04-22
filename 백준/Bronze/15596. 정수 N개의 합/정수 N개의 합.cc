/*정수 N개의 합*/

#include <vector>

using namespace std;

//최댓값이 1,000,000 * 3,000,000 이므로 long long 자료형 사용
long long sum(std::vector<int>& a) {
	long long ans = 0;

	for (int i = 0; i < a.size(); i++) {
		ans += a[i];
	}
	return ans;
}
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> gemKinds(gems.begin(), gems.end());
    int totalKinds = gemKinds.size();
    
    unordered_map<string, int> count;
    int n = gems.size();
    int l = 0, r = 0;
    int minLen = n + 1;
    int ansL = 0, ansR = 0;
    
    // 투 포인터 탐색
    while (true) {
        if (count.size() == totalKinds) {
            // 모든 종류를 포함했으면 왼쪽 줄이기
            if (r - l < minLen) {
                minLen = r - l;
                ansL = l + 1;  // 진열대는 1부터 시작
                ansR = r;      // r은 이미 +1 상태라 그냥 r
            }
            count[gems[l]]--;
            if (count[gems[l]] == 0) count.erase(gems[l]);
            l++;
        } else {
            if (r == n) break; // 오른쪽 끝 도달
            count[gems[r]]++;
            r++;
        }
    }
    
    return {ansL, ansR};
}

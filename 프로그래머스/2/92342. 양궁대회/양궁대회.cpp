#include <string>
#include <vector>

using namespace std;

// 최대 점수 차
int maxDiff = 0;
// 최적의 화살 배치
vector<int> bestCase;

// 점수차 계산
int getDiff (const vector<int>& ryan, const vector<int>& apeach){
    int rScore = 0;
    int aScore = 0;
    for(int i = 0;i<11;i++){
        if(ryan[i] == 0 && apeach[i] == 0) continue;
        if(ryan[i] > apeach [i]) rScore += (10 - i);
        else aScore+= (10 - i);
    }
    
    return rScore - aScore;
}

bool compareLower (const vector<int>& a, const vector<int>& b){
    for(int i = 10; i>=0;i--){
        if(a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return false;
}

void dfs(int idx, int remain, vector<int>& ryan, const vector<int>& apeach){
    
    // 모든 점수를 탐색한 경우
    if(idx == 11){
        // 화살이 남아 있다면, 0점에 모두 쏜다.
        if(remain > 0){
            ryan[10] += remain;
        }
        
        int diff = getDiff(ryan, apeach);
        
        // 라이언이 이긴 경우만 고려
        if(diff > 0){
            if(diff > maxDiff) {
                maxDiff = diff;
                bestCase = ryan;
            }
            
            // 점수차가 같으면 낮은 점수를 더 맞힌 경우로 갱신
            else if(diff == maxDiff && compareLower(ryan, bestCase)){
                bestCase = ryan;
            }
        }
        
        // 복구
        if(remain > 0) ryan[10] -= remain;
        return;
    }
    
    int need = apeach[idx]+1;
    
    // 현재 점수를 이기기 위해 쏘는 경우
    if(remain >= need){
        ryan[idx] = need;
        dfs(idx+1, remain-need, ryan, apeach);
        ryan[idx]=0;
    }
    // 해당 점수를 포기하는 경우
    dfs(idx+1, remain, ryan, apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> ryan(11,0);
    bestCase.clear();
    maxDiff = 0;
    
    dfs(0, n, ryan, info);
    
    if(bestCase.empty()) return {-1};
    answer = bestCase;
    return answer;
}
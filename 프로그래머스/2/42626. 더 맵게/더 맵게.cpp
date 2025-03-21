#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    if(pq.top() > K){ //미니가 k를 넘으면 바로 반환
        return answer;
    }
    
    while(pq.size() != 1 && pq.top() < K){
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        int cal = f + s * 2;
        pq.push(cal);
        ++answer;
    }
    if(pq.size() == 1 && pq.top() < K){
        answer = -1;
    }
    
    return answer;
}
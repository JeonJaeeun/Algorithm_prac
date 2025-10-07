#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

// 시간 "HH:MM" -> 분 단위로 변환
int timeToMin(string t){
    // stoi: 문자열을 정수로 바꿔주는 함수 (string -> int)
    int h = stoi(t.substr(0,2));
    int m = stoi(t.substr(3,2));
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // 차량번호 -> 입차시간
    map<string, int> inTime;
    // 차량번호 -> 누적 주차 시간
    map<string, int> totalTime;
    
    // "07:59 5961 OUT"
    for(auto& r:records){
        // "07:59"
        string time = r.substr(0,5);
        // "5961"
        string car = r.substr(6,4);
        // "OUT"
        string type = r.substr(11);
        
        // "479"
        int minute = timeToMin(time);
        
        if(type == "IN"){
            // "5961 -> 479"
            inTime[car] = minute;
        }
        else{
            totalTime[car] += minute - inTime[car]; // 누적 주차시간 계산
            inTime.erase(car); // 출차했으니 입차기록 제거
        }
    }
    
    // 아직 출차하지 않은 차량 (23:59 출차 처리)
    for(auto &p : inTime){
        totalTime[p.first] += (23 * 60 + 59) - p.second;
    }
    
    // 요금 계산
    // 기본 시간, 기본 요금, 단위 시간, 단위 요금
    int baseTime = fees[0];
    int baseFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    
    for(auto&p : totalTime){
        int t = p.second;
        int fee = baseFee;
        if(t>baseTime){
            fee += ceil((t-baseTime)/(double)unitTime) * unitFee;
        }
        answer.push_back(fee);
    }
    
    return answer;
}
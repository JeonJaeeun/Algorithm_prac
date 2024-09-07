#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    
    int n = friends.size();
    
    /* 친구 이름을 인덱스로 변환: map 사용 */
    map<string, int> gift_dict;
    for(int i = 0; i < n; i++){
        gift_dict[friends[i]] = i;
    }
    
    /* 정의 */
    // 서로 주고받은 선물 : 2차원 배열
    vector<vector<int>> gift_table(n, vector<int>(n,0));
    
    // 선물 지수
    vector<int> gift_score(n,0);
    
    // 총 선물 수
    vector<int> total_gift(n,0);
    
    /* gifts 배열 -> a,b로 변환 */
    for(string gift: gifts){
        string a, b;
        
        stringstream ss(gift);
        ss >> a >> b;
        
        /* a -> b 준 선물 기록 -> a 선물지수 증가, b 선물지수 감소 */
        gift_table[gift_dict[a]][gift_dict[b]]++;
        gift_score[gift_dict[a]]++;
        gift_score[gift_dict[b]]--;
    }
    
    /* 다음 달 선물 계산 */
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            // i = j 비교하지 않음
            if(i == j){
                continue;
            }
            
            // i가 j보다 선물을 더 많이 줬으면, 다음달 i += 1
            if(gift_table[i][j] > gift_table[j][i]){
                total_gift[i] += 1;
            }
            
            // i와 j의 준 선물 개수가 같으면, 선물 지수 비교
            // 작은 선물 지수를 가진 사람이 줘야함 (큰 선물 지수를 가진 사람 다음달 += 1)
            else if(gift_table[i][j] == gift_table[j][i]){
                if(gift_score[i] > gift_score[j]){
                    total_gift[i] += 1;
                }
            }
        }
    }
    
    /* 가장 선물 많이 받는 사람 */
    int max_gift = total_gift[0];
    for(int i = 0; i < total_gift.size(); ++i){
        if(total_gift[i] > max_gift){
            max_gift = total_gift[i];
        }
    }
    return max_gift;

}
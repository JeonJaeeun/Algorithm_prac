#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0; // 사라진 인형 개수 카운트
    int height = board.size(); // 격자 높이
    int moves_cnt = moves.size(); // 크레인 작동 횟수
    stack<int> basket;

    // 크레인 작동
    for(int i = 0; i < moves_cnt; i++) {
        int pos = moves[i] - 1;  // 크레인 작동 위치 (열)

        for(int j = 0; j < height; j++) { // (행; 작을수록 높은 위치)
            if(board[j][pos] == 0) { // 상단에 인형이 없는 경우 -> 아래칸 탐색
                continue;
            }

            // 인형 집어올리기
            int doll = board[j][pos];
            board[j][pos] = 0;

            if(!basket.empty() && doll == basket.top()) { // 같은 모양의 인형이 나란히 쌓이는 경우
                basket.pop(); // basket에서 인형 제거하기
                answer += 2;
            }
            else { // 다른 모양의 인형이 나란히 쌓이는 경우
                basket.push(doll); // basket에 인형 쌓기
            }
            break;
        }

    }
    return answer;
}
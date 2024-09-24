#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0]; //한 변의 길이를 저장하는 변수
    int r = board.size(); //행(row) 수
    int c = board[0].size(); //열(column) 수

    //두번째 행부터 배열 순차 탐색
    for(int i = 1;i<r;i++){
        for(int j =1;j<c;j++){
            if(board[i][j] == 1){
                board[i][j] = 1 + min({board[i-1][j-1], board[i-1][j], board[i][j-1]});
                answer = max(answer, board[i][j]);
            }
        }
    }
    return answer * answer;
}
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int total; //총 경우의 수를 세는 변수
vector<int> col; //퀸의 위치를 저장할 배열

//현재 level(x번째 행)에 퀸을 배치할 때, 이전에 배치한 퀸들과 충돌하는지 확인
bool check(int level){
    for(int i = 0;i<level;i++){
        //같은 열에 있는지 확인 or 대각선에 퀸이 있는지 확인
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i){
            return false;
        }
    }
    return true;
}

//현재 배치할 행, 체스판의 크기
void nqueen(int x, int n){
    if( x==n ){ //모든 퀸을 성공적으로 배치했을 때 (x가 n에 도달했을 때)
        total++;
    }
    else{
        for(int i = 0;i<n;i++){
            col[x] = i; //x번째 행의 i번째 열에 퀸을 배치
            if(check(x)){ //퀸을 배치한 후 유효한지 확인
                nqueen(x+1, n); //다음 행으로 넘어가서 퀸을 배치
            }
        }
    }
}

int solution(int n) {
    total = 0;
    col.resize(n);
    nqueen(0,n);
    return total;
}
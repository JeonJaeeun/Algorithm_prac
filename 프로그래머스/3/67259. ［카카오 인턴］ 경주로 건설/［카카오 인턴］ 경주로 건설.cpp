#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int n;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void bfs(vector<vector<int>>& board, vector<vector<vector<int>>>& cost, int sx, int sy){
    queue<tuple<int,int,int,int>> q;
    q.push({sx,sy,-1,0});
    
    while(!q.empty()){
        auto [x,y,dir,c] = q.front();
        q.pop();
        
        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] == 1) continue;
            
            int newCost = c + 100;
            if(dir != -1 && dir != d) newCost += 500;
            
            if(cost[nx][ny][d] > newCost){
                cost[nx][ny][d] = newCost;
                q.push({nx,ny,d,newCost});
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 1e9;
    
    n = board.size();
    vector<vector<vector<int>>> cost(n, vector<vector<int>>(n, vector<int>(4, 1e9)));

    bfs(board, cost, 0, 0);
    
    for (int d = 0; d < 4; d++)
        answer = min(answer, cost[n-1][n-1][d]);
    
    return answer;
}
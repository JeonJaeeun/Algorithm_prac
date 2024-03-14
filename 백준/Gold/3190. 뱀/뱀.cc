#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
    //우, 상, 좌, 하
    int dr[4] = { 0, -1, 0, 1 };
    int dc[4] = { 1, 0, -1, 0 };

    //뱀 초기화
    deque<ci> snake;
    snake.push_front(ci(0, 0));
    board[0][0] = 1;

    int t = 0, head = 0; //시간, 뱀의 머리 방향
    while (true) {
        t++;
        //뱀의 머리가 위치하게될 칸
        int nr = snake.front().first + dr[head];
        int nc = snake.front().second + dc[head];

        //게임 종료 조건 : 벽에 부딪히거나, 자기자신의 몸과 부딪힘
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1)
            break;

        if (board[nr][nc] != 2) { //이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }

        //뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
        snake.push_front(ci(nr, nc));
        board[nr][nc] = 1;

        //이번에 방향을 변환하는지 확인
        if (cmd[t] == 'L') //왼쪽 회전
            head = (head + 1) % 4;
        if (cmd[t] == 'D') //오른쪽 회전
            head = (head + 3) % 4;
    }
    return t;
}

int solution(int n, int k, int l, vector<vector<int>>& apple, vector<int>& rotation_t, vector<char>& rotation_d) {
    vector<vector<int>> board(n, vector<int>(n));
    map<int, char> cmd;
    for (int i = 0; i < k; i++) //사과 위치
        board[apple[i][0] - 1][apple[i][1] - 1] = 2; //사과 표시

    for (int i = 0; i < l; i++)
        cmd[rotation_t[i]] = rotation_d[i]; //시간, 회전 정보 저장

    int answer = playGame(n, board, cmd);
    return answer;
}

int main() {
    int n, k, l;
    //입력
    cin >> n >> k;
    vector<vector<int>> apple(k, vector<int>(2));
    for (int i = 0; i < k; i++) //사과 위치
        cin >> apple[i][0] >> apple[i][1];
    cin >> l;
    vector<int> rotation_t(l); //시간
    vector<char> rotation_d(l); //방향
    for (int i = 0; i < l; i++) //회전 정보
        cin >> rotation_t[i] >> rotation_d[i];
    //연산
    int answer = solution(n, k, l, apple, rotation_t, rotation_d);
    //출력0
    cout << answer;
    return 0;
}
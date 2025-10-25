#include <vector>
using namespace std;

vector<vector<int>> rotate90(vector<vector<int>> key) {
    int m = key.size();
    vector<vector<int>> rotated(m, vector<int>(m));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            rotated[j][m - 1 - i] = key[i][j];
    return rotated;
}

bool check(int x, int y, vector<vector<int>>& key, vector<vector<int>>& lock) {
    int m = key.size(), n = lock.size();
    vector<vector<int>> tmp = lock;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            int nx = i + x;
            int ny = j + y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            tmp[nx][ny] += key[i][j];
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(tmp[i][j] != 1) return false;
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size(), n = lock.size();
    for(int r = 0; r < 4; r++){
        for(int x = -m+1; x < n; x++){
            for(int y = -m+1; y < n; y++){
                if(check(x, y, key, lock)) return true;
            }
        }
        key = rotate90(key);
    }
    return false;
}

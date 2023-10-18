//
// Created by LG on 2023-10-18.
//
#include <iostream>
#include <queue>

using namespace std;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int R, C;
char board[1001][1001]{};
int ans = -1;

vector<vector<int>> fire_bfs(const vector<pair<int, int>>& fire){
    vector<vector<int>> minute(R, vector<int>(C, -1));

    for(int k=0; k<fire.size(); k++) {
        queue<pair<int, int>> q;
        bool visited[1001][1001] = {false, };

        int sr = fire[k].first;
        int sc = fire[k].second;
        q.push({sr, sc});
        visited[sr][sc] = true;
        minute[sr][sc] = 1;

        while (!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                    continue;
                if (visited[nr][nc])
                    continue;
                if (board[nr][nc] == '#' || board[nr][nc] == 'F')
                    continue;

                //아직 불이 닿은 적이 없거나 원래 닿았던 불보다 더 빨리 닿는다면
                if(minute[nr][nc] == -1 || minute[nr][nc] > minute[cr][cc] + 1) {
                    minute[nr][nc] = minute[cr][cc] + 1;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    return minute;
}

void jihoon_bfs(int sr, int sc, const vector<vector<int>>& f_minute){
    queue<pair<int, int>> q;
    vector<vector<int>> minute(R, vector<int>(C, -1));
    bool visited[1001][1001] = {false, };

    q.push({sr, sc});
    visited[sr][sc] = true;
    minute[sr][sc] = 1;

    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        if(cr == 0 || cr == R-1 || cc == 0 || cc == C-1){
            ans = minute[cr][cc];
            return;
        }
        for(int i=0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            if(visited[nr][nc])
                continue;
            if(board[nr][nc] == '#')
                continue;

            //불이 닿을 수 없는 곳이거나, 불보다 지훈이가 빨리 닿는 곳이라면
            if(f_minute[nr][nc] == -1 || minute[cr][cc] + 1 < f_minute[nr][nc]){
                minute[nr][nc] = minute[cr][cc] + 1;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

}

int main(){
    cin >> R >> C;
    pair<int, int> jihoon;
    vector<pair<int, int>> fire;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> board[i][j];
            if(board[i][j] == 'J')
                jihoon = {i, j};
            else if(board[i][j] == 'F')
                fire.emplace_back(i, j);
        }
    }

    vector<vector<int>> f_minute = fire_bfs(fire);
    jihoon_bfs(jihoon.first, jihoon.second, f_minute);

    if(ans == -1)
        cout << "IMPOSSIBLE";
    else
        cout << ans;
}
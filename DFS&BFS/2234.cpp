//
// Created by LG on 2024-05-15.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
int deltas[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; ///서 북 동 남
int room_cnt = 0, max_size = 0, max_size2 = 0;

int bfs(int sr, int sc) {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    int cnt = 1;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int wall = 1;
        for(int k=0; k<4; k++) {
            if((board[r][c] & wall) != wall) { //벽이 있는 쪽이라면
                int nr = r + deltas[k][0];
                int nc = c + deltas[k][1];
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    cnt++;
                    q.push({nr, nc});
                }
            }
            wall *= 2;
        }
    }

    return cnt;
}

int main() {
    cin >> M >> N;

    board.assign(N, vector<int>(M, 0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }

    visited.assign(N, vector<bool>(M, false));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!visited[i][j]) {
                room_cnt++;
                int size = bfs(i, j);
                if(size > max_size) {
                    max_size = size;
                }

            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            for(int k=1; k<=8; k*=2) {
                if((board[i][j] & k) == k) { //벽이 있다면
                    board[i][j] -= k;
                    visited.assign(N, vector<bool>(M, false));
                    int size = bfs(i, j);
                    if(size > max_size2) {
                        max_size2 = size;
                    }
                    board[i][j] += k;
                }
            }
        }
    }

    cout << room_cnt << '\n' << max_size << '\n' << max_size2;
}

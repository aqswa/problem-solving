//
// Created by LG on 2023-10-18.
//
#include <iostream>

using namespace std;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int N, M;
int board[502][502]{};
bool visited[502][502] = {false, };

int cnt = 0, max_size = 0; //그림 개수, 그림 최대 크기

int dfs(int r, int c, int cur_size){ //!스택이 아닌 재귀를 이용해 dfs를 간단하게 구현할 수 있음.

    visited[r][c] = true;
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc] && board[nr][nc]){
            visited[nr][nc] = true;
            cur_size = dfs(nr, nc, cur_size); //!얘랑 아랫줄 순서가 바뀌면 안됨
            cur_size++;
        }
    }

    return cur_size;
}

int main() {
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] && !visited[i][j]){
                cnt++;
                int cur_size = dfs(i, j, 1);
                if(cur_size > max_size)
                    max_size = cur_size;
            }
        }
    }

    cout << cnt << '\n' << max_size;

}
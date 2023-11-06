//
// Created by LG on 2023-11-05.
//
#include <iostream>
#include <queue>
#define MAX 400

using namespace std;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int N, M;
int board[182][182];
vector<vector<int>> dist;

void dfs(int r, int c){
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;
        if(dist[nr][nc] > dist[r][c] + 1){
            dist[nr][nc] = dist[r][c] + 1;
            dfs(nr, nc);
        }
    }
}

int main(){
    cin >> N >> M;
    dist.assign(N, vector<int>(M, MAX));
    
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            board[i][j] = s[j] - '0';
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] == 1){
                dist[i][j] = 0;
                dfs(i, j);
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

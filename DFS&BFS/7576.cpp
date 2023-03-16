//
// Created by LG on 2023-03-16.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(vector<vector<int>> &box, queue<pair<int, int>> q, int n, int m){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int xx = x + dx[k];
            int yy = y + dy[k];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && !box[xx][yy]){
                box[xx][yy] = box[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }

    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!box[i][j])
                return -1;
            if(box[i][j] > max)
                max = box[i][j];
        }
    }
    return max-1;
}

int main(){

    int m, n;
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) //bfs를 시작 토마토마다 따로 돌려서 거리를 비교하는 것이 아니라, 토마토가 있는 칸을 먼저 q에 전부 넣어놓고 bfs를 하면 처음 방문하는 곳이
                q.push({i, j}); //가장 가까운 거리가 된다는 bfs의 원리를 이해해야 시간초과가 나지 않는 문제
        }
    }

    cout << bfs(box, q, n, m);
}

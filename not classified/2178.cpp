//
// Created by LG on 2022-05-04.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<vector<int>> graph, int n, int m){
    queue<pair<int, int>> q;
    q.push({0, 0});
    //vector<vector<bool>> check(n, vector<bool>(m, false));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int tx = x;
            int ty = y;
            tx += dx[i];
            ty += dy[i];
            if(tx >=0 && tx < n && ty >=0 && ty < m && graph[tx][ty] != 0){
                if(graph[tx][ty] == 1 || graph[tx][ty] > graph[x][y]+1){
                    graph[tx][ty] = graph[x][y]+1;
                    q.push({tx, ty});
                }
            }
        }
    }
    return graph[n-1][m-1];
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++)
            graph[i][j] = s[j]-'0';
    }

    cout << bfs(graph, n, m);
}

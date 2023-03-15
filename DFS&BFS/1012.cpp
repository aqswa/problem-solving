//
// Created by LG on 2023-03-15.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(vector<vector<bool>> ground, int m, int n ){
    vector<vector<bool>> visited(m, vector<bool>(n, false)); //bool visited[m][n]; 은 안된다.
    int cnt = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(ground[i][j] && !visited[i][j]){
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    pair<int, int> next = q.front();
                    q.pop();
                    int x = next.first;
                    int y = next.second;
                    if(!visited[x][y]) {
                        visited[x][y] = true;
                        for (int k = 0; k < 4; k++) {
                            int xx = x + dx[k];
                            int yy = y + dy[k];
                            if (xx >= 0 && xx < m && yy >= 0 && yy < n && ground[xx][yy] && !visited[xx][yy]) {
                                q.push({xx, yy});
                            }
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m, k;
        cin >> m >> n >> k;
        vector<vector<bool>> ground(m, vector<bool>(n, false));
        while(k--){
            int a, b;
            cin >> a >> b;
            ground[a][b] = true;
        }
        cout << bfs(ground, m, n) << '\n';
    }
}

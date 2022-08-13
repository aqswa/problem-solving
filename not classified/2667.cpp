//
// Created by LG on 2022-05-12.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<int> findComplex(int n, vector<vector<int>> map){
    vector<vector<bool>> check(n, vector<bool>(n, false));
    vector<int> size;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] && !check[i][j]){
                queue<pair<int, int>> q;
                int cnt = 1;
                q.push({i, j});
                check[i][j] = true;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int tx = x + dx[k];
                        int ty = y + dy[k];
                        if (tx >= 0 && tx < n && ty >= 0 && ty < n && map[tx][ty] && !check[tx][ty]) {
                            q.push({tx, ty});
                            check[tx][ty] = true;
                            cnt++;
                        }
                    }
                }
                size.push_back(cnt);
            }
        }
    }
    return size;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
            map[i][j] = s[j]-'0';
    }

    vector<int> ans = findComplex(n, map);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << '\n';
}
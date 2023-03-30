//
// Created by LG on 2023-03-30.
//
#include <iostream>
#include <vector>

using namespace std;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};
vector<vector<int>> house;

vector<vector<int>> diffuse(int n, int m){
    vector<vector<int>> diffused(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(house[i][j] && house[i][j] != -1){ //미세먼지가 있는 칸이면
                int cnt = 0, amount = house[i][j] / 5;
                for(int k=0; k<4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m || house[nr][nc] == -1)
                        continue;
                    diffused[nr][nc] += amount;
                    cnt++;
                }
                diffused[i][j] -= amount * cnt;
            }
        }
    }
    return diffused;
}

void clean(int n, int m, int top, int bottom){
    //위쪽 공청기
    for(int i=top-1; i>0; i--){
        house[i][0] = house[i-1][0];
    }

    for(int i=0; i<m-1; i++){
        house[0][i] = house[0][i+1];
    }

    for(int i=0; i<top; i++){
        house[i][m-1] = house[i+1][m-1];
    }

    for(int i=m-1; i>1; i--){
        house[top][i] = house[top][i-1];
    }
    house[top][1] = 0;

    //아래쪽 공청기
    for(int i=bottom+1; i<n-1; i++){
        house[i][0] = house[i+1][0];
    }

    for(int i=0; i<m-1; i++){
        house[n-1][i] = house[n-1][i+1];
    }

    for(int i=n-1; i>bottom; i--){
        house[i][m-1] = house[i-1][m-1];
    }

    for(int i=m-1; i>1; i--){
        house[bottom][i] = house[bottom][i-1];
    }
    house[bottom][1] = 0;
}

int main(){

    int n, m, t;
    cin >> n >> m >> t;
    house.assign(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> house[i][j];
        }
    }

    int top = 0, bottom = 0;
    for(int i=0; i<n; i++){
        if(house[i][0] == -1){
            top = i;
            bottom = i+1;
            break;
        }
    }

    while(t--) {
        vector<vector<int>> diffused = diffuse(n, m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                house[i][j] += diffused[i][j];
            }
        }

        clean(n, m, top, bottom);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(house[i][j] != -1)
                ans += house[i][j];
        }
    }

    cout << ans;
}

//
// Created by LG on 2023-03-22.
//
#include <iostream>
#include <vector>

using namespace std;

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1}; //아래, 오른쪽이 +
int n, m;
vector<vector<int>> sky;
vector<vector<bool>> cloud;

void copy_water(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(cloud[i][j]){ //구름이 있는 칸이라면
                for(int k=2; k<=8; k+=2){ //4가지 방향 대각선 2, 4, 6, 8
                    int row = i + dy[k]; //대각선 행
                    int col = j + dx[k]; //대각선 열
                    if(row > n || row <= 0 || col > n || col <= 0){ //경계 바깥에 있다면
                        continue;
                    }
                    if (sky[row][col]) //대각선 방향에 물이 1 이상이라면
                        sky[i][j]++;
                }
            }
        }
    }
}

void make_cloud(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(cloud[i][j]) //구름이 있는 칸이라면 구름 없앰
                cloud[i][j] = false;
            else{  //구름이 없는 칸이라면
                if(sky[i][j] > 1){ //물이 2이상이라면
                    sky[i][j] -= 2; //물 2 줄이고
                    cloud[i][j] = true; //구름 생성함
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;

    sky.assign(n+1, vector<int>(n+1, 0));
    cloud.assign(n+1, vector<bool>(n+1, false));

    cloud[n][1] = cloud[n][2] = cloud[n-1][1] = cloud[n-1][2] = true;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> sky[i][j];
        }
    }

    while(m--){
        int d, s;
        cin >> d >> s;
        vector<pair<int, int>> moved;
        for(int i=1; i<=n; i++){ //모든 칸에 대해서
            for(int j=1; j<=n; j++){
                if(cloud[i][j]){ //구름이 있는 칸이라면
                    cloud[i][j] = false;
                    int row = i + dy[d]*s;   //구름이 이동한 행이 방향*거리
                    int col = j + dx[d]*s;   //구름이 이동한 열이 방향*거리
                    if(row <= 0)
                        row = n - abs(row) % n;
                    else if(row > n) {
                        row %= n;
                        if(row == 0)
                            row = n;
                    }

                    if(col <= 0)
                        col = n - abs(col) % n;
                    else if(col > n) {
                        col %= n;
                        if(col == 0)
                            col = n;
                    }

                    moved.emplace_back(row, col);
                }
            }
        }

        for(int k=0; k<moved.size(); k++){
            cloud[moved[k].first][moved[k].second] = true;
            sky[moved[k].first][moved[k].second]++;
        }

        copy_water(); //방금 구름이 있었던 칸에 대해서 물복사
        make_cloud(); //구름이 있었던 칸을 제외하고 새로운 구름 생성
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans += sky[i][j];
        }
    }

    cout << ans;
}
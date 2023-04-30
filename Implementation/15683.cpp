//
// Created by LG on 2023-03-31.
//
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

vector<vector<int>> room;
int ans = 64;
int n, m;

void east(vector<ci> & areas, int r, int c){ //동쪽
    for(int i=c+1; i<m; i++){
        if(room[r][i] == 6) {
            break;
        }
        else if(room[r][i] == 0){
            room[r][i] = -1;
            areas.emplace_back(r, i);
        }
    }
}

void north(vector<ci> &areas, int r, int c){ //북쪽
    for(int i=r-1; i>=0; i--){
        if(room[i][c] == 6){
            break;
        }
        else if(room[i][c] == 0){
            room[i][c] = -1;
            areas.emplace_back(i, c);
        }
    }
}

void west(vector<ci> &areas, int r, int c){ //서쪽
    for(int i=c-1; i>=0; i--){
        if(room[r][i] == 6){
            break;
        }
        else if(room[r][i] == 0){
            room[r][i] = -1;
            areas.emplace_back(r, i);
        }
    }
}

void south(vector<ci> &areas, int r, int c){ //남쪽
    for(int i=r+1; i<n; i++){
        if(room[i][c] == 6){
            break;
        }
        else if(room[i][c] == 0){
            room[i][c] = -1;
            areas.emplace_back(i, c);
        }
    }
}

vector<ci> find_area(int r, int c, int type, int dir){

    if(type == 1){ //첫 번째 타입 cctv
        vector<ci> areas;
        if(dir == 0){ //동쪽 방향
            east(areas, r, c);
        }
        else if(dir == 1){ //북
            north(areas, r, c);
        }
        else if(dir == 2){ //서
            west(areas, r, c);
        }
        else{ //남
            south(areas, r, c);
        }
        return areas;
    }
    else if(type == 2){ //두 번째 타입 cctv
        vector<ci> areas;
        if(dir == 0){
            east(areas, r, c);
            west(areas, r, c);
        }
        else{
            north(areas, r, c);
            south(areas, r, c);
        }
        return areas;
    }
    else if(type == 3){
        vector<ci> areas;
        if(dir == 0){
            east(areas, r, c);
            north(areas, r, c);
        }
        else if(dir == 1){
            north(areas, r, c);
            west(areas, r, c);
        }
        else if(dir == 2){
            west(areas, r, c);
            south(areas, r, c);
        }
        else{
            south(areas, r, c);
            east(areas, r, c);
        }
        return areas;
    }
    else if(type == 4){
        vector<ci> areas;
        if(dir == 0){
            east(areas, r, c);
            south(areas, r, c);
            west(areas, r, c);
        }
        else if(dir == 1){
            south(areas, r, c);
            west(areas, r, c);
            north(areas, r, c);
        }
        else if(dir == 2){
            west(areas, r, c);
            north(areas, r, c);
            east(areas, r, c);
        }
        else{
            north(areas, r, c);
            east(areas, r, c);
            south(areas, r, c);
        }
        return areas;
    }
    else{
        vector<ci> areas;
        east(areas, r, c);
        south(areas, r, c);
        west(areas, r, c);
        north(areas, r, c);
        return areas;
    }
}

void solve(int r, int c){
    //cout << r << ' ' << c << '\n';
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(room[i][j] == 0)
                cnt++;
        }
    }
    if(cnt < ans) {
        ans = cnt;
    }

    for(int i=r; i<n; i++){
        for(int j=c; j<m; j++){
            if(j == m-1) //이중 for문 backtracking에서 다음 행을 탐색할 때 c번째 열부터 탐색하게 되므로
                c = 0;   //마지막 열에 도달했다면 c를 0으로 초기화해 다음 행을 0번째 열부터 탐색하도록 함.
            if(room[i][j] == 0 || room[i][j] == 6 || room[i][j] == -1)
                continue;
            if(room[i][j] == 1){
                for(int k=0; k<4; k++){
                    vector<ci> areas = find_area(i, j, room[i][j], k);
                    if(j == m-1)
                        solve(i+1, 0);
                    else
                        solve(i, j+1);
                    for(auto a : areas){
                        room[a.first][a.second] = 0;
                    }
                }
            }
            else if(room[i][j] == 2){
                for(int k=0; k<2; k++){
                    vector<ci> areas = find_area(i, j, room[i][j], k);
                    if(j == m-1)
                        solve(i+1, 0);
                    else
                        solve(i, j+1);
                    for(auto a: areas){
                        room[a.first][a.second] = 0;
                    }
                }
            }
            else if(room[i][j] == 3){
                for(int k=0; k<4; k++){
                    vector<ci> areas = find_area(i, j, room[i][j], k);
                    if(j == m-1)
                        solve(i+1, 0);
                    else
                        solve(i, j+1);
                    for(auto a: areas){
                        room[a.first][a.second] = 0;
                    }
                }
            }else if(room[i][j] == 4){
                for(int k=0; k<4; k++){
                    vector<ci> areas = find_area(i, j, room[i][j], k);
                    if(j == m-1)
                        solve(i+1, 0);
                    else
                        solve(i, j+1);
                    for(auto a: areas){
                        room[a.first][a.second] = 0;
                    }
                }
            }
            else if(room[i][j] == 5){
                vector<ci> areas = find_area(i, j, room[i][j], 0);
                if(j == m-1)
                    solve(i+1, 0);
                else
                    solve(i, j+1);
                for(auto a: areas){
                    room[a.first][a.second] = 0;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    room.assign(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> room[i][j];
        }
    }

    solve(0, 0);

    cout << ans;
}

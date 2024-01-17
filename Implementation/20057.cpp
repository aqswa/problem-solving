//
// Created by LG on 2024-01-15.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int ans = 0;
int dir = 0; //토네이도 전진 방향
vector<vector<double>> ratio;
int sand[500][500];
int deltas[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void move_sand(int r, int c){
    int amount = sand[r][c];
    for(int i=-2; i<=2; i++){
        for(int j=-2; j<=2; j++){
            int nr = r + i;
            int nc = c + j;
            int move = floor(amount * ratio[i+2][j+2]);
            if(nr >= 0 && nr < N && nc >= 0 && nc < N){ // 이동한 모래가 격자 내부에 있다면
                sand[nr][nc] += move;
            }
            else{
                ans += move;
            }
            sand[r][c] -= move;
        }
    }

    int nr = r + deltas[dir][0];
    int nc = c + deltas[dir][1];
    if(nr >= 0 && nr < N && nc >= 0 && nc < N){ // 이동한 모래가 격자 내부에 있다면
        sand[nr][nc] += sand[r][c];
    }
    else{
        ans += sand[r][c];
    }

    sand[r][c] = 0;
}

void anti_clockwise(){
    vector<vector<double>> new_ratio(5, vector<double>(5, 0));
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            new_ratio[i][j] = ratio[j][4-i];
        }
    }
    ratio = new_ratio;
}

int main(){
    cin >> N;

    ratio = {{0, 0, 0.05, 0, 0}, {0, 0.1, 0, 0.1, 0}, {0.02, 0.07, 0, 0.07, 0.02}, {0, 0.01, 0, 0.01, 0}, {0, 0, 0, 0, 0}};
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> sand[i][j];
        }
    }

    int r = N/2;
    int c = N/2;
    int move = 1;

    while(move < N){
        anti_clockwise(); //비율 보드를 시계 반대 방향으로 90도 회전

        for(int i=0; i<move; i++) {
            r += deltas[dir][0];
            c += deltas[dir][1];
            move_sand(r, c);
        }

        dir = (dir + 1) % 4; //전진 방향 바꿈
        anti_clockwise(); //비율 보드를 시계 반대 방향으로 90도 회전
        for(int i=0; i<move; i++) {
            r += deltas[dir][0];
            c += deltas[dir][1];
            move_sand(r, c);
        }

        dir = (dir + 1) % 4; //전진 방향 바꿈
        move++;
    }

    anti_clockwise();
    for(int i=0; i<move; i++){
        r += deltas[dir][0];
        c += deltas[dir][1];
        move_sand(r, c);
    }

    cout << ans;
}
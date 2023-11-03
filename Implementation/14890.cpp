//
// Created by LG on 2023-11-03.
//
#include <iostream>

#define MAX 101

using namespace std;

int N, L;
int board[MAX][MAX];

int check_cross(int idx){
    int cnt = 0;
    //행 확인
    int flag = false;
    int stair_idx = 1; //경사로 놓기 시작할 수 있는 idx
    for(int i=1; i<N; i++){
        int gap = board[idx][i] - board[idx][i+1];
        if(abs(gap) > 1){ //간격이 1보다 큰 경우
            flag = true;
            break;
        }
        else if(gap == 1){ //칸이 내려가는 경우
            if(N-i < L){ //경사로가 범위 넘어가는 경우
                flag = true;
                break;
            }
            for(int j=1; j<L; j++){
                if(board[idx][i+j] != board[idx][i+j+1]){
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
            stair_idx = i+L+1;
        }
        else if(gap == -1){ //칸이 올라가는 경우
            if(i-L < 0 || i-L+1 < stair_idx){ //경사로가 범위 넘어가거나 이미 경사로 있는 칸을 넘는 경우
                flag = true;
                break;
            }
            stair_idx = i+1;
        }
    }

    if(!flag)
        cnt++;

    //열 확인
    flag = false;
    stair_idx = 1; //경사로 놓기 시작할 수 있는 idx
    for(int i=1; i<N; i++){
        int gap = board[i][idx] - board[i+1][idx];
        if(abs(gap) > 1){ //간격이 1보다 큰 경우
            flag = true;
            break;
        }
        else if(gap == 1){ //칸이 내려가는 경우
            if(N-i < L){ //경사로가 범위 넘어가는 경우
                flag = true;
                break;
            }
            for(int j=1; j<L; j++){
                if(board[i+j][idx] != board[i+j+1][idx]){
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
            stair_idx = i+L+1;
        }
        else if(gap == -1){ //칸이 올라가는 경우
            if(i-L < 0 || i-L+1 < stair_idx){ //경사로가 범위 넘어가거나 이미 경사로 있는 칸을 넘는 경우
                flag = true;
                break;
            }
            stair_idx = i+1;
        }
    }

    if(!flag)
        cnt++;

    return cnt;
}

int main() {
    cin >> N >> L;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    for(int i=1; i<=N; i++){
        cnt += check_cross(i);
    }

    cout << cnt;
}

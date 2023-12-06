//
// Created by LG on 2023-12-06.
//
#include <iostream>

using namespace std;

int board[301][301] = {0};

int main(){
    int t;
    cin >> t;

    int num = 1;
    for(int i=1; i<301; i++){
        board[i][1] = num;
        int increase = i;
        for(int j=2; j<301; j++){
            board[i][j] = board[i][j-1] + increase;
            increase++;
        }
        num += i+1;
    }

    for(int i=1; i<=t; i++){
        int p, q, px, py, qx, qy;
        cin >> p >> q;
        for(int m=1; m<301; m++){
            for(int n=1; n<301; n++){
                if(board[m][n] == p){
                    px = m;
                    py = n;
                }
                if(board[m][n] == q){
                    qx = m;
                    qy = n;
                }
            }
        }

        int nx = px + qx;
        int ny = py + qy;
        cout << "#" << i << " " << board[nx][ny] << '\n';
    }
}

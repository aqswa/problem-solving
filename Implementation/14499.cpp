//
// Created by LG on 2023-03-29.
//
#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {0, 0, -1, 1}; //+1 동 서 북 남
int dc[4] = {1, -1, 0, 0};

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    vector<int> dice(7, 0);
    int row = x, col = y;
    while(k--){
        int dir;
        cin >> dir;

        int nr = row + dr[dir-1];
        int nc = col + dc[dir-1];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m){
            continue;
        }
        row = nr;
        col = nc;
        vector<int> temp(7, 0);
        temp = dice;
        if(dir == 1){ //동 서 북 남
            dice[1] = temp[3];
            dice[3] = temp[6];
            dice[4] = temp[1];
            dice[6] = temp[4];
        }
        else if(dir == 2){
            dice[1] = temp[4];
            dice[3] = temp[1];
            dice[4] = temp[6];
            dice[6] = temp[3];
        }
        else if(dir == 3){ //북
            dice[1] = temp[2];
            dice[2] = temp[6];
            dice[5] = temp[1];
            dice[6] = temp[5];
        }
        else{ //남
            dice[1] = temp[5];
            dice[2] = temp[1];
            dice[5] = temp[6];
            dice[6] = temp[2];
        }

        if(board[row][col] == 0){
            board[row][col] = dice[1];
        }
        else{
            dice[1] = board[row][col];
            board[row][col] = 0;
        }
        cout << dice[6] << '\n';
    }
}

//
// Created by LG on 2023-03-29.
//
#include <iostream>
#include <vector>

using namespace std;

int dice_r[4] = {0, 0, 0, 0}; //남쪽으로 굴리는게 +
int dice_c[4] = {0, 0, 0, 0}; //동쪽으로 굴리는게 +

const int dr[5] = {0, 0, 0, -1, 1}; // 1동 2서 3북 4남
const int dc[5] = {0, 1, -1, 0, 0};

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    int row = x, col = y, index_r = 0, index_c = 0;
    while(k--){
        int dir;
        cin >> dir;
        int nr = row + dr[dir];
        int nc = col + dc[dir];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m){
            continue;
        }
        row += dr[dir];
        col += dc[dir];
        if(dir == 1){ //동
            index_c++;
            index_c = (index_c + 4) % 4;
            if(board[nr][nc] == 0){
                board[nr][nc] = dice_c[index_c];
            }
            else{
                dice_c[index_c] = board[nr][nc];
                if(index_c%2 == 0)
                    dice_r[index_r] = board[nr][nc];
                board[nr][nc] = 0;
            }
            if(index_c < 2)
                cout << dice_c[index_c + 2] << '\n';
            else
                cout << dice_c[index_c - 2] << '\n';
        }
        else if(dir == 2){ //서
            index_c--;
            index_c = (index_c + 4) % 4;
            if(board[nr][nc] == 0)
                board[nr][nc] = dice_c[index_c];
            else{
                dice_c[index_c] = board[nr][nc];
                if(index_c%2 == 0)
                    dice_r[index_r] = board[nr][nc];
                board[nr][nc] = 0;
            }
            if(index_c < 2)
                cout << dice_c[index_c + 2] << '\n';
            else
                cout << dice_c[index_c - 2] << '\n';
        }
        else if(dir == 3){ //북
            index_r--;
            index_r = (index_r + 4) % 4;
            if(board[nr][nc] == 0)
                board[nr][nc] = dice_r[index_r];
            else{
                dice_r[index_r] = board[nr][nc];
                if(index_r%2 == 0)
                    dice_c[index_c] = board[nr][nc];
                board[nr][nc] = 0;
            }
            if(index_r < 2)
                cout << dice_r[index_r + 2] << '\n';
            else
                cout << dice_r[index_r - 2] << '\n';
        }
        else{ //남
            index_r++;
            index_r = (index_r + 4) % 4;
            if(board[nr][nc] == 0)
                board[nr][nc] = dice_r[index_r];
            else{
                dice_r[index_r] = board[nr][nc];
                if(index_r%2 == 0)
                    dice_c[index_c] = board[nr][nc];
                board[nr][nc] = 0;
            }
            if(index_r < 2)
                cout << dice_r[index_r + 2] << '\n';
            else
                cout << dice_r[index_r - 2] << '\n';
        }
    }
}

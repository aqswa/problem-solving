//
// Created by LG on 2022-05-19.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int ColorBlind(int n, vector<vector<char>> board){
    vector<vector<bool>> check(n, vector<bool>(n, false));
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j]){
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if(!check[x][y]){
                        check[x][y] = true;
                        for(int k=0; k<4; k++){
                            int tx = x + dx[k];
                            int ty = y + dy[k];
                            if(tx >=0 && tx < n && ty >=0 && ty < n && !check[tx][ty]) {
                                if(board[i][j] == 'R' || board[i][j] == 'G'){
                                    if(board[tx][ty] == 'R' || board[tx][ty] == 'G')
                                        q.push({tx, ty});
                                }
                                else{
                                    if(board[tx][ty] == board[i][j])
                                        q.push({tx, ty});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int Normal(int n, vector<vector<char>> board){
    vector<vector<bool>> check(n, vector<bool>(n, false));
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j]){
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if(!check[x][y]){
                        check[x][y] = true;
                        for(int k=0; k<4; k++){
                            int tx = x + dx[k];
                            int ty = y + dy[k];
                            if(tx >=0 && tx < n && ty >=0 && ty < n && !check[tx][ty] && board[tx][ty] == board[x][y])
                                q.push({tx, ty});
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){

    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, ' '));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
            board[i][j] = s[j];
    }

    cout << Normal(n, board) << ' ' << ColorBlind(n, board);
}

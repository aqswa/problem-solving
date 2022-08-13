//
// Created by LG on 2022-03-27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    string key, crypt;
    cin >> key >> crypt;

    int m = key.length();
    int n = crypt.length()/m;
    vector<vector<char>> board(n, vector<char>(m, ' '));
    vector<int> order(m);
    vector<char> keyword(key.begin(), key.end());
    vector<bool> visited(m);

    sort(keyword.begin(), keyword.end());

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(key[i] == keyword[j] && !visited[j]){
                visited[j] = true;
                order[i] = j;
                break;
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            board[j][i] = crypt[n*i+j];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << board[i][order[j]];
        }
    }
}

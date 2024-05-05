//
// Created by LG on 2024-05-05.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> board;
int a, b, c;

void count_paper(int sr, int sc, int length) {

    int type = board[sr][sc];
    bool flag = false;
    for(int i=sr; i<sr+length; i++) {
        for(int j=sc; j<sc+length; j++) {
            if(board[i][j] != type) {
                flag = true;
                break;
            }
        }
        if(flag) { //2중 for문 탈출
            break;
        }
    }

    if(flag) {
        for(int i=sr; i<sr+length; i+=length/3) {
            for(int j=sc; j<sc+length; j+=length/3) {
                count_paper(i, j, length/3);
            }
        }
    } else {
        if(type == -1) {
            a++;
        } else if(type == 0 ) {
            b++;
        } else {
            c++;
        }
    }
}

int main() {
    cin >> N;
    board.assign(N, vector<int>(N, 0));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    count_paper(0, 0, N);

    cout << a << '\n' << b << '\n' << c;
}

//
// Created by LG on 2024-05-05.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> answer;

void recursion(int r, int c, int height) {
    if(height == 3) {
        answer[r][c] = '*';
        answer[r+1][c-1] = '*';
        answer[r+1][c+1] = '*';
        for(int i=c-2; i<c+3; i++) {
            answer[r+2][i] = '*';
        }
        return;
    }

    recursion(r, c, height/2);
    recursion(r+height/2, c-height/2, height/2);
    recursion(r+height/2, c+height/2, height/2);
}

int main() {

    ios_base ::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N;
    answer.assign(N, vector<char>(2*N-1, ' '));

    recursion(0, N-1, N);

    for(int i=0; i<N; i++) {
        for(int j=0; j<2*N-1; j++) {
            cout << answer[i][j];
        }
        cout << '\n';
    }
}

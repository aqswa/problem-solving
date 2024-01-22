//
// Created by LG on 2024-01-22.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
int board[20][20];
int score[20][20];
int deltas[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<int> dice = { 0, 1, 2, 3, 4, 5, 6 };

//  2
//4 1 3
//  5
//  6

void roll_dice(int dir) {
    vector<int> temp = dice;
    if (dir == 0) { // 동 남 서 북
        temp[1] = dice[4];
        temp[3] = dice[1];
        temp[4] = dice[6];
        temp[6] = dice[3];
    }
    else if (dir == 1) {
        temp[2] = dice[6];
        temp[1] = dice[2];
        temp[5] = dice[1];
        temp[6] = dice[5];
    }
    else if (dir == 2) {
        temp[4] = dice[1];
        temp[1] = dice[3];
        temp[3] = dice[6];
        temp[6] = dice[4];
    }
    else {
        temp[1] = dice[5];
        temp[5] = dice[6];
        temp[6] = dice[2];
        temp[2] = dice[1];
    }

    dice = temp;
}

void bfs() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool visited[20][20] = { false };
            queue<pair<int, int>> q;
            q.push({ i, j });
            visited[i][j] = true;
            int cnt = board[i][j];

            while (!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + deltas[k][0];
                    int nc = c + deltas[k][1];
                    if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc]) {
                        if (board[nr][nc] == board[i][j]) {
                            visited[nr][nc] = true;
                            cnt += board[i][j];
                            q.push({ nr, nc });
                        }
                    }
                }
            }

            score[i][j] = cnt;
        }
    }

}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    int dir = 0;
    int row = 0;
    int col = 0;

    bfs();

    while (K--) {
        if (dir == 0 && col == M - 1) {
            dir = 2;
        }
        else if (dir == 1 && row == N - 1) {
            dir = 3;
        }
        else if (dir == 2 && col == 0) {
            dir = 0;
        }
        else if (dir == 3 && row == 0) {
            dir = 1;
        }

        row += deltas[dir][0];
        col += deltas[dir][1];

        roll_dice(dir);

        ans += score[row][col];

        if (dice[6] > board[row][col]) {
            dir = (dir + 1) % 4;
        }
        else if (dice[6] < board[row][col]) {
            dir = (dir + 3) % 4;
        }

        //cout << row << ' ' << col << ' ' << dir << ' ' << score[row][col] << ' ' << ans << '\n';
    }

    cout << ans;
}

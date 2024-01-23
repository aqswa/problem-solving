//
// Created by LG on 2024-01-23.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int N, Q;
vector<vector<int>> board;

int deltas[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void clockwise(int length) {

    vector<vector<int>> new_board(N, vector<int>(N, 0));
    for (int i = 0; i <= N - length; i += length) {
        for (int j = 0; j <= N - length; j += length) {
            for (int r = 0; r < length; r++) {
                for (int c = 0; c < length; c++) {
                    new_board[i + r][j + c] = board[i + length - 1 - c][j + r];
                }
            }
        }
    }

    board = new_board;
}

void melt() {
    vector<pair<int, int>> temp;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] <= 0) {
                continue;
            }

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int r = i + deltas[k][0];
                int c = j + deltas[k][1];
                if (r >= 0 && r < N && c >= 0 && c < N) {
                    if (board[r][c] > 0) {
                        cnt++;
                    }
                }
            }

            if (cnt < 3) {
                temp.emplace_back(i, j);
            }
        }
    }

    for(pair<int, int> t : temp){
        board[t.first][t.second]--;
    }
}

int bfs() {
    int max = 0;
    int visited[64][64] = { false };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && board[i][j] > 0) {
                int cnt = 1;
                visited[i][j] = true;
                queue<pair<int, int>> q;
                q.push({ i, j });

                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nr = r + deltas[k][0];
                        int nc = c + deltas[k][1];
                        if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc] && board[nr][nc] > 0) {
                            visited[nr][nc] = true;
                            q.push({ nr, nc });
                            cnt++;
                        }
                    }
                }

                if (cnt > max) {
                    max = cnt;
                }
            }
        }
    }

    return max;
}

int main() {
    cin >> N >> Q;

    N = pow(2, N); //전체 격자 한 변 길이
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int L;
    for(int i=0; i<Q; i++) {
        cin >> L;
        clockwise(pow(2, L)); //2^L 격자 회전
        melt(); //주변에 얼음 있는 칸 3개 미만이면 얼음 1 줄임
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += board[i][j];
        }
    }

    int largest = bfs();

    cout << sum << '\n' << largest;
}

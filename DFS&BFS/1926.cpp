#include <iostream>
#include <queue>

using namespace std;

int N, M;
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int main(){
    cin >> N >> M;

    int board[502][502]{};
    bool visited[502][502] = {false, };

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    int cnt = 0, max = 0; //그림 개수, 그림 최대 크기

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] && !visited[i][j]) {
                cnt++; //그림 개수 1 증가
                visited[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                int size = 1;
                while (!q.empty()) {
                    int cr = q.front().first;
                    int cc = q.front().second;
                    q.pop();

                    for(int k=0; k<4; k++){
                        int nr = cr + dr[k];
                        int nc = cc + dc[k];
                        if(nr >= 0 && nr < N && nc >= 0 && nc < M && board[nr][nc] && !visited[nr][nc]){
                            visited[nr][nc] = true;
                            size++;
                            q.push({nr, nc});
                        }
                    }
                }
                if(size > max)
                    max = size;
            }
        }
    }

    cout << cnt << '\n' << max;

}
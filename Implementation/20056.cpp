//
// Created by LG on 2023-04-08.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct info{
    int m, d, s;
};

int main(){
    int n, mm, t;
    cin >> n >> mm >> t;

    vector<vector<stack<info> > > board(n+1, vector<stack<info> >(n+1, stack<info>()));
    while(mm--){
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        info i = {m, d, s};
        board[r][c].push(i);
    }

    while(t--){
        vector<vector<stack<info> > > moved(n+1, vector<stack<info> >(n+1, stack<info>()));
        for(int i=1; i<=n; i++){ //각 칸마다
            for(int j=1; j<=n; j++){
                while(!board[i][j].empty()){ //파이어볼이 빌 때까지 파이어볼 이동시킴
                    info inf = board[i][j].top();
                    board[i][j].pop();
                    int nr = i + dr[inf.d]*inf.s;
                    int nc = j + dc[inf.d]*inf.s;
                    if(nr > n){
                        while(nr > n)
                            nr -= n;
                    }
                    else if(nr < 1){
                        while(nr < 1)
                            nr += n;
                    }

                    if(nc > n){
                        while(nc > n)
                            nc -= n;
                    }
                    else if(nc < 1){
                        while(nc < 1)
                            nc += n;
                    }
                    moved[nr][nc].push(inf);
                }
            }
        }
        //이동한 파이어볼로 바꿔줌
        board = moved;
        //같은 칸 파이어볼 합치기
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(board[i][j].size() > 1){ //파이어볼이 2개 이상이라면
                    int mass = 0, speed = 0;
                    int cnt = 0;
                    bool flag = true; //true이면 모두 홀수이거나 모두 짝수
                    while(!board[i][j].empty()){ //파이어볼이 남지 않을때까지 mass 더하고 방향 비교
                        cnt++;
                        info cur = board[i][j].top();
                        board[i][j].pop();
                        mass += cur.m;
                        speed += cur.s;
                        if(flag && !board[i][j].empty()){ //다음 파이어볼이 있다면
                            if(cur.d % 2 != board[i][j].top().d % 2) //현재 파이어볼 방향과 다음 파이어볼 방향의 홀짝 여부가 다르다면 false
                                flag = false;
                        }
                    }
                    mass /= 5;
                    speed /= cnt;
                    if(mass != 0) { //나눈 질량이 0이라면 없앰
                        if (flag) { //방향 홀짝 여부가 같다면
                            for (int k = 0; k < 7; k += 2) {
                                board[i][j].push({mass, k, speed});
                            }
                        } else {
                            for (int k = 1; k < 8; k += 2) {
                                board[i][j].push({mass, k, speed});
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            while(!board[i][j].empty()){
                ans += board[i][j].top().m;
                board[i][j].pop();
            }
        }
    }

    cout << ans;
}

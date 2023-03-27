//
// Created by LG on 2023-03-28.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};
typedef pair<int, int> ci;

vector<vector<int>> countries;

vector<vector<ci>> bfs(int n, int l, int r){
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<ci>> unions;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){ //아직 연합에 속하지 않은 나라이면
                vector<ci> new_union; //새로운 연합 생성
                queue<ci> q;
                q.push({i, j});
                visited[i][j] = true;
                new_union.emplace_back(i, j); //연합에 시작 나라도 포함
                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nr = row + dr[k];
                        int nc = col + dc[k];
                        if(nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc])
                            continue;
                        int diff = abs(countries[row][col] - countries[nr][nc]);
                        if(diff >= l && diff <= r){
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                            new_union.emplace_back(nr, nc);
                        }
                    }
                }
                if(new_union.size() != 1)
                    unions.push_back(new_union);
            }
        }
    }
    return unions;
}

int main(){
    int n, l, r;
    cin >> n >> l >> r;

    countries.assign(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> countries[i][j];
        }
    }

    vector<vector<ci>> unions;
    int cnt = 0;
    while(true){
        vector<vector<ci>> unions = bfs(n, l, r); //연합의 벡터 배열
        if(unions.empty()) //size() 말고 empty()가 적합함.
            break;
        cnt++;
        for(auto u: unions){ //생성된 모든 연합에 대해
            int sum = 0;
            for(auto c: u){ //연합에 속하는 나라들의 인구 합
                sum += countries[c.first][c.second];
            }
            int population = sum / u.size(); //새로운 인구 = (연합의 인구 합) / (연합 수)
            for(auto c: u){ //새로운 인구 입력
                countries[c.first][c.second] = population;
            }
        }
    }

    cout << cnt;
}

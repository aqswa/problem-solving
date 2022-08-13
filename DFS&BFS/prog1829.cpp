//
// Created by LG on 2022-03-14.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int main(){
    int m = 6;
    int n = 4;

    vector<vector<int>> picture(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> picture[i][j];
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] || !picture[i][j])
                continue;

            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;  //!이거 빼먹음 안된다......!

            int cnt = 1;
            while(!q.empty()){
                pair<int, int> cur = q.front();
                q.pop();

                for(int k=0; k<4; k++){
                    int x = cur.first;
                    int y = cur.second;
                    x += dx[k];
                    y += dy[k];
                    if(x >=0 && x < m && y >=0 && y < n){
                        if(picture[x][y] == picture[cur.first][cur.second] && !visited[x][y]){
                            visited[x][y] = true;  //생각하면서 풀기
                            q.push({x, y});
                            cnt++;
                        }
                    }
                }
            }
            number_of_area++;
            max_size_of_one_area = max(cnt, max_size_of_one_area);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    cout << answer[0] << answer[1];
    return 0;
}

//
// Created by LG on 2023-03-27.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

vector<vector<int>> classroom; //0이면 빈 칸
int n;

struct seat{
    int row;
    int col;
    int likes;
    int empty;
};

struct compare{
    bool operator()(seat &s1, seat &s2){
        if(s1.likes == s2.likes){
            if(s1.empty == s2.empty){
                if(s1.row == s2.row){
                    return s1.col > s2.col;
                }
                return s1.row > s2.row;
            }
            return s1.empty < s2.empty;
        }
        return s1.likes < s2.likes;
    }
};

void check_friends(priority_queue<seat, vector<seat>, compare> &pq, vector<int> like){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!classroom[i][j]){ //비어있는 자리라면
                seat s = {i, j, 0, 0};
                for(int k=0; k<4; k++){ //인접한 자리를 확인
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x < 0 || x >= n || y < 0 || y >= n){ //경계를 넘어갔다면 넘어감
                        continue;
                    }
                    if(!classroom[x][y]) //인접한 자리가 비어있는 자리라면
                        s.empty++;
                    else{ //인접한 자리가 비어있는 자리 아니라면
                        for(int i=1; i<=4; i++){ //좋아하는 학생 리스트 돌면서
                            if(classroom[x][y] == like[i]){ //좋아하는 학생이면
                                s.likes++; //좋아하는 학생 수 증가
                                break;
                            }
                        }
                    }
                }
                pq.push(s); //비어있는 자리 정보 struct pq에 push
            }
        }
    }
}

int main(){
    cin >> n;

    vector<vector<int>> like(n*n, vector<int>(5, 0));
    map<int, vector<int>> like_map;
    for(int i=0; i<n*n; i++){
        cin >> like[i][0];
        for(int j=1; j<5; j++){
            cin >> like[i][j];
            like_map[like[i][0]].push_back(like[i][j]);
        }
    }

    classroom.assign(n, vector<int>(n, 0));
    for(int i=0; i<n*n; i++){
        priority_queue<seat, vector<seat>, compare> pq;
        check_friends(pq, like[i]);
        seat s = pq.top();
        classroom[s.row][s.col] = like[i][0];
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt = 0;
            for(int k=0; k<4; k++){ //인접한 칸들 확인
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || x >= n || y < 0 || y >= n)
                    continue;
                for(int l=0; l<4; l++){
                    if(classroom[x][y] == like_map[classroom[i][j]][l]) { //인접한 자리에 앉은 애가 좋아하는 친구 리스트에 있는 애라면
                        cnt++;
                    }
                }
            }
            if(cnt != 0){
                ans += pow(10, cnt-1);
            }
        }
    }

    cout << ans;
}

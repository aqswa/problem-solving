//
// Created by LG on 2023-03-09.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dfs(vector<vector<bool>> network){
    int cnt = 0;
    vector<bool> check(network.size(), false);
    queue<int> q;
    q.push(1);
    check[1] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=1; i<network.size(); i++){
            if(network[cur][i]){
                if(!check[i]){
                    check[i] = true;
                    cnt++;
                    q.push(i);
                }
            }
        }
    }

    return cnt;
}

int main(){
    int n, c;
    cin >> n >> c;

    vector<vector<bool>> network(n+1, vector<bool>(n+1, 0));

    for(int i=0; i<c; i++){
        int s, e;
        cin >> s >> e;
        network[s][e] = true;
        network[e][s] = true; //!양방향 그래프 주의
    }

    cout << dfs(network);
}

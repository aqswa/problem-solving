//
// Created by LG on 2022-04-06.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int t;

    while(t--){
        //입력
        int n, k, w;
        cin >> n >> k; //건물 개수, 규칙 개수
        vector<int> time(n+1, 0);
        for(int i=1; i<=n; i++)
            cin >> time[i];
        vector<vector<int>> graph(n+1, vector<int>());
        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            graph[y].push_back(x); //y를 짓기 위해서 x를 반드시 지어야함.
        }
        cin >> w; //승리하기 위해 지어야 하는 건물

        vector<int> dp(n+1, 0);
        dp[w] = time[w];
        int cur = w;
        queue<int> q;
        while(true){
            for(int i=0; i<graph[cur].size(); i++){
                q.push(graph[cur][i]);
                dp[graph[cur][i]] = max(dp[graph[cur][i]], )
            }
        }
    }
}

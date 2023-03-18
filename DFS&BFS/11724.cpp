//
// Created by LG on 2023-03-18.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(vector<vector<int>> graph, int n){
    bool visited[1001] = {false,};
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt++;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int vertex = q.front();
                q.pop();
                for(int j=0; j<graph[vertex].size(); j++){
                    if(!visited[graph[vertex][j]]){
                        visited[graph[vertex][j]] = true;
                        q.push(graph[vertex][j]);
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>());

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << solve(graph, n);
}

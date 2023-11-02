//
// Created by LG on 2023-11-01.
//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;

bool dfs(int idx, int before){
    visited[idx] = true;
    for(int i=0; i<graph[idx].size(); i++){
        int next = graph[idx][i];
        if(next == before)
            continue;
        if(visited[next] == true)
            return false;
        if(!dfs(next, idx))
            return false;
    }
    return true;
}

int main(){
    int N, M;
    int case_cnt = 0;

    while(true){
        case_cnt++;
        int cnt = 0;
        cin >> N >> M; //정점의 수, 간선의 수
        if(N == 0 && M == 0){
            break;
        }

        graph.assign(N+1, vector<int>());
        visited.assign(N+1, false);
        for(int i=0; i<M; i++){
            int u, v;
            cin >> u >> v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        for(int i=1; i<=N; i++){
            if(dfs(i, 0))
                cnt++;
        }

        if(cnt == 0){
            cout << "Case " << case_cnt << ": No trees." << '\n';
        }
        else if(cnt == 1){
            cout << "Case " << case_cnt << ": There is one tree." << "\n";
        }
        else{
            cout << "Case " << case_cnt << ": A forest of " << cnt << " trees." << '\n';
        }
    }

    return 0;
}

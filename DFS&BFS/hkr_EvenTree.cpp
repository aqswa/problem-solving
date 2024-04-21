#include <bits/stdc++.h>

using namespace std;

int answer = 0;

int dfs(int node, vector<bool> visited, vector<vector<int>> graph) {
    
    int child_cnt = 1; 
    for(int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        if(!visited[next]) {
            visited[next] = true;
            child_cnt += dfs(next, visited, graph);
        }
    }
    
    if(child_cnt %2 == 0 && node != 1) {
        answer++;
    }
    cout << node << ' ' << child_cnt << '\n';
    return child_cnt;
}

// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    vector<vector<int>> graph(t_nodes+1, vector<int>());
    
    for(int i=0; i<t_edges; i++) {
        int u = t_from[i];
        int v = t_to[i];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(t_nodes+1, false);
    visited[1] = true;
    dfs(1, visited, graph);
    
    return answer;
}

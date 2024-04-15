#include <bits/stdc++.h>

using namespace std;

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if(c_lib < c_road) {
        return (long)c_lib * (long)n;
    }
    
    vector<vector<int>> graph(n+1, vector<int>());
    
    for(int i=0; i<cities.size(); i++) {
        int u = cities[i][0];
        int v = cities[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<bool> visited(n+1, false);
    long long answer = 0;
    
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            int cnt = 1;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                
                for(int j=0; j<graph[cur].size(); j++) {
                    int next = graph[cur][j];
                    if(!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                        cnt++;
                    }
                }
            }
            
            answer += (long long)c_lib + (long long)(cnt-1) * (long long)c_road;
        }
    }
    
    return answer;
}

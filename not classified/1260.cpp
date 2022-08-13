//
// Created by LG on 2022-04-17.
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> graph, int n, int s){
    vector<int> check(n, false);
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        if(!check[cur]) {
            check[cur] = true;
            cout << cur << ' ';
            for (int i = graph[cur].size()-1; i>=0; i--) {
                int next = graph[cur][i];
                if (check[next] != true)
                    st.push(next);
            }
        }
    }
}

void bfs(vector<vector<int>> graph, int n, int s){
    vector<int> check(n, false);
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(!check[cur]) {
            cout << cur << ' ';
            check[cur] = true;
            for (int i = 0; i < graph[cur].size(); i++) {
                int next = graph[cur][i];
                if (!check[next])
                    q.push(next);
            }
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> graph(n+1, vector<int>());
    while(m--){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(graph, n+1, s);
    cout << '\n';
    bfs(graph, n+1, s);
}

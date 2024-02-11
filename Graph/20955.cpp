//
// Created by LG on 2024-02-11.
//
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int N, M;
vector<vector<int>> graph;
int graph_cnt = 0;
int cycle_cnt = 0;

void bfs() {
    vector<int> visited(N + 1, false);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            graph_cnt++;
            queue<int> q;
            q.push({ i });
            visited[i] = true;
            set<int> vertex; //방문한 정점 저장
            vertex.insert(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < graph[cur].size(); j++) {
                    int next = graph[cur][j];
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push({next});
                        vertex.insert(next);
                    }
                }
            }
            int cnt = 0;
            for(auto v : vertex){
                cnt += graph[v].size(); //방문한 정점에 연결된 간선 개수
            }
            cycle_cnt += cnt / 2 - vertex.size() + 1;
        }
    }
}

int main() {

    cin >> N >> M; //정점 개수, 간선 개수

    //그룹 개수 -1 + 사이클 개수

    graph.assign(N + 1, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();

    cout << graph_cnt + cycle_cnt - 1;
}

//
// Created by LG on 2024-05-18.
//
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

#define INTMAX 1e9

using namespace std;

int N, A, B;
vector<vector<pair<int, int>>> graph;

int get_max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    cin >> N >> A >> B; //방 개수, 로봇 위치
    graph.assign(N+1, vector<pair<int, int>>());

    for(int i=0; i<N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    queue<tuple<int, int, int>> q;
    q.push({A, 0, 0}); //정점, 시작점으로부터의 거리, 가장 긴 통로 길이
    vector<bool> visited(N+1, false);
    visited[A] = true;

    while(!q.empty()) {
        int node = get<0>(q.front()); //현재 노드
        int cur = get<1>(q.front()); //현재 거리
        int max = get<2>(q.front());
        q.pop();

        if(node == B) {
            cout << cur - max;
            return 0;
        }

        for(int i=0; i<graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = graph[node][i].second;
            if(!visited[next_node]) {
                visited[next_node] = true;
                q.push({next_node, cur + next_weight, get_max(max, next_weight)});
            }
        }
    }

}

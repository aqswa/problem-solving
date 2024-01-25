//
// Created by LG on 2024-01-25.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>


using namespace std;

int N, M; //노드 개수, 알고 싶은 노드 쌍 개수
vector<vector<pair<int, int>>> tree(1001, vector<pair<int, int>>());
int dist[1001];

int solve(int s, int e) {
    queue<int> q;
    q.push({s});
    dist[s] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        //트리는 사이클이 없으므로 인접 정점으로부터 거리 더한 값이 시작점으로부터의 거리
        for(int i=0; i<tree[cur].size(); i++){
            int next = tree[cur][i].first;
            int cost = tree[cur][i].second;
            if(dist[next] < 0){
                dist[next] = dist[cur] + cost;
                q.push(next);
            }
        }
    }

    return dist[e];
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N-1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        tree[a].push_back({ b, w });
        tree[b].push_back({ a, w });
    }

    while (M--) {
        int a, b;
        cin >> a >> b;
        memset(dist, -1, sizeof(dist));
        cout << solve(a, b) << '\n';
    }
}

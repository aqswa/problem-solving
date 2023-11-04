//
// Created by LG on 2023-11-02.
//
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;
int V, max_dist, max_vertex;
vector<vector<ci>> graph;

void dfs(int s, int before, int dist){
    if(dist > max_dist){
        max_dist = dist;
        max_vertex = s;
    }

    for(int i=0; i<graph[s].size(); i++){
        if(graph[s][i].first == before)
            continue;
        dfs(graph[s][i].first, s, dist + graph[s][i].second); //현재까지의 가중치 + 연결된 간선의 가중치
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V;
    graph.assign(V+1, vector<ci>());

    for(int i=0; i<V; i++){
        int a;
        cin >> a;
        while(true){
            int v, d;
            cin >> v;
            if(v == -1)
                break;
            cin >> d;
            graph[a].emplace_back(v, d); //(연결된 정점, 가중치) 입력
        }
    }

    //트리에서 임의의 정점에서 가장 먼 정점을 구한 뒤,
    //그 정점에서 가장 먼 정점까지의 거리를 구하면 트리의 지름.
    //트리의 모든 노드가 루트 노드가 될 수 있어서
    dfs(1, 0, 0);

    dfs(max_vertex, 0, 0);

    cout << max_dist;
}


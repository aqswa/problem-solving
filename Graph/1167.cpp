//
// Created by LG on 2023-11-02.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e9;
int V;
vector<vector<ci>> graph;

int dijkstra(int s){
    vector<int> distance(V+1, INF);
    vector<bool> visited(V+1, false);
    distance[s] = 0;

    priority_queue<ci, vector<ci>> pq; //(연결된 정점, 가중치)

    pq.push({0, s}); //(거리, 정점 번호)
    while(!pq.empty()){
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        for(int i=0; i<graph[v].size(); i++){
            int next_v = graph[v][i].first;
            int next_d = graph[v][i].second;
            if(visited[next_v])
                continue;
            if(distance[next_v] > d + next_d){
                distance[next_v] = d + next_d;
                pq.push({distance[next_v], next_v});
            }
        }
    }

    int max_val = 0;
    for(int i=1; i<=V; i++){
        if(distance[i] > max_val)
            max_val = distance[i];
    }
    return max_val;
}

int main(){
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

    int total_max = 0;
    for(int i=0; i<V; i++){
        int max_val = dijkstra(i+1);
        if(max_val > total_max)
            total_max = max_val;
    }

    cout << total_max;
}


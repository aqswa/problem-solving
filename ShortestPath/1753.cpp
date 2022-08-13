//
// Created by LG on 2022-03-19.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e9;

vector<int> dijkstra(vector<vector<ci>> graph, int v, int s){
    vector<int> distance(v+1, INF);

    priority_queue<ci, vector<ci>, greater<>> pq; //오름차순
    pq.push({0, s}); //시작점으로부터의 거리, 정점
    distance[s] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if(weight > distance[node])
            continue;

        for(int i=0; i<graph[node].size(); i++){
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if(distance[next_node] > next_weight){
                distance[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }

    return distance;

}

int main(){

    int v, e, s;
    cin >> v >> e >> s;
    vector<vector<ci>> graph(v+1, vector<ci>(0));

    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        //graph[v].emplace_back(u, w);
    }

    vector<int> distance = dijkstra(graph, v, s);
    for(int i=1; i<=v; i++){
        if(distance[i] == INF)
            cout << "INF" << '\n';
        else
            cout << distance[i] << '\n';
    }
}

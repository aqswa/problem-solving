//
// Created by LG on 2023-03-12.
//
#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;

using namespace std;

int main(){

    int n, m; //도시 개수, 버스 개수
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1);
    for(int i=0; i<m; i++){
        int s, e, price;
        cin >> s >> e >> price;
        graph[s].emplace_back(e, price);
    }

    int from, to;
    cin >> from >> to;

    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, INF); //출발점으로부터 모든 정점까지의 최단거리를 갱신
    distance[from] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //pair first에 대한 오름차순 우선순위 큐
    pq.push({distance[from], from});
    while(!pq.empty()){
        pair<int, int> next = pq.top();
        pq.pop();
        if(visited[next.second]){
            continue;
        }
        visited[next.second] = true; //!방문하지 않은 정점 중에서 비용이 가장 작은 정점을 방문 처리한다.
        for(int i=0; i<graph[next.second].size(); i++){
            int price = graph[next.second][i].second; //현재 정점에서 다음 정점까지의 비용
            int vertex = graph[next.second][i].first; //다음 정점의 인덱스
            if(!visited[vertex] && next.first + price < distance[vertex]){
                distance[vertex] = next.first + price; //시작점으로부터의 거리 갱신
                pq.push({distance[vertex], vertex});
            }
        }
    }

    cout << distance[to];
}

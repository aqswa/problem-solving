//
// Created by LG on 2022-03-20.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 2*10e7;

vector<int> dijkstra(vector<vector<ci>> graph, int start, int n){

    vector<int> distance(n+1, INF);
    //vector<bool> visited(n+1, false);
    distance[start] = 0;
    //visited[start] = true;

    priority_queue<ci, vector<ci>, greater<>> pq;
    pq.push({0, start});

    /*for(int i=0; i<graph[start].size(); i++){
        distance[i] = graph[start][i];
    }*/
    while(!pq.empty()){
        int weight = pq.top().first; //우선순위 큐는 힙으로 구현되기 때문에 top을 쓴다.
        int node = pq.top().second;
        pq.pop(); //!!

        if(weight > distance[node]) // weight != distance[node]  이미 확인했던 정점이라면.
            continue;  //가장 가까운 정점을 뽑은건데 그보다 더 짧은 거리가 존재한다면 이미 집합 S에 속해있음.
        //갱신되며 큐에 입력된 거리가 현재 거리보다 짧거나 같다면(?) 집합에 속하지 않음.
        //weight가 distance[node]보다 짧을 수는 없음.
        for(int i=0; i<graph[node].size(); i++){
            int next_node = graph[node][i].first;
            if(graph[node][i].second + weight < distance[next_node]){
                distance[next_node] = graph[node][i].second + weight;
                pq.push({distance[next_node], next_node});
            }
        }
    }
    return distance;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    vector<vector<ci>> graph(n+1, vector<ci>(0));

    for(int i=0; i<fares.size(); i++){
        graph[fares[i][0]].emplace_back(fares[i][1], fares[i][2]);
        graph[fares[i][1]].emplace_back(fares[i][0], fares[i][2]);
    }

    vector<int> from_s = dijkstra(graph, s, n);
    int answer = 2*INF;
    for(int i=1; i<=n; i++){
        int share = from_s[i];
        vector<int> from_i = dijkstra(graph, i, n);
        answer = min(answer, share + from_i[a] + from_i[b]);
    }

    return answer;
}

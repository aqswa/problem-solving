//
// Created by LG on 2023-10-11.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

const int INF = 1e9;
int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dijkstra(vector<vector<ci>> &graph, vector<int> &distance){
    priority_queue<ci, vector<ci>, greater<>> pq;
    pq.push({0, 0}); //시작점으로부터의 거리, 정점

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
}

int main(){
    cin >> N >> M;
    vector<vector<int>> maze(N, vector<int>(M, 0));
    vector<vector<ci>> graph(N*M, vector<ci>(0));
    vector<int> distance(N*M, INF);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> maze[i][j];
        }
    }
    distance[0] = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(nx >= 0 && nx < M && ny >= 0 && ny < N){
                    if(maze[nx][ny] == 0){ //빈 방이라면 이동거리 0
                        graph[i*N+j].emplace_back(0, ny*N+nx);
                    }
                    else{ //벽이라면 이동거리 1
                        graph[i*N+j].emplace_back(1, ny*N+nx);
                    }
                }
            }
        }
    }

    dijkstra(graph, distance);

    cout << distance[N*M-1];
}

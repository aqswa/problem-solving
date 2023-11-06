//
// Created by LG on 2023-11-06.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
int T, N; //테스트 케이스 수, 편의점 수

int beer_distance(ci p1, ci p2){
    int manhattan = abs(p1.first - p2.first) + abs(p1.second - p2.second);
    if(manhattan > 1000){
        return -1;
    }
    else{
        if(manhattan%50 == 0)
            return manhattan/50;
        else
            return manhattan/50 + 1;
    }
}

bool bfs(vector<vector<int>> graph){
    queue<int> q;
    q.push(0); //집이 0
    vector<int> visited(N+2, false);
    visited[0] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i];
            if(visited[next])
                continue;
            visited[next] = true;
            q.push(next);
        }
    }

    if(visited[N+1]) //페스티벌에 도달 가능하면
        return true;
    else
        return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        cin >> N; //편의점 수
        vector<ci> coord(N+2);
        cin >> coord[0].first >> coord[0].second;
        for(int i=1; i<=N; i++){
            cin >> coord[i].first >> coord[i].second;
        }
        cin >> coord[N+1].first >> coord[N+1].second;

        vector<vector<int>> graph(N+2); //정점
        for(int i=0; i<N+2; i++){
            for(int j=0; j<N+2; j++){
                if(i == j)
                    continue;
                int dist = beer_distance(coord[i], coord[j]);
                if(dist != -1){
                    graph[i].emplace_back(j); //1000m 이하라면 연결된 정점으로 입력
                }
            }
        }

        if(bfs(graph))
            cout << "happy" << '\n';
        else
            cout << "sad" << '\n';
    }
}

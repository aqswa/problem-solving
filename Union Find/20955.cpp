//
// Created by LG on 2024-02-11.
//
#include <vector>
#include <iostream>

using namespace std;

int N, M;
vector<int> parent;

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return find(parent[x]);
}

void merge(int x1, int x2){
    int p1 = find(x1);
    int p2 = find(x2);

    if(p1 > p2){
        parent[p1] = p2;
    }
    else{
        parent[p2] = p1;
    }
}

int main() {

    cin >> N >> M; //정점 개수, 간선 개수
    parent.assign(N+1, 0);
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    //그룹 개수 -1 + 사이클 개수

    int graph_cnt = 0;
    int cycle_cnt = 0;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        if(find(u) == find(v)){ //하나씩 연결하면서 사이클이 생기는 간선을 찾으므로 사이클을 중복으로 세지 않음.
            cycle_cnt++;
        }
        else{
            merge(u, v);
        }
    }

    for(int i=1; i<=N; i++){
        if(parent[i] == i){
            graph_cnt++;
        }
    }

    cout << graph_cnt + cycle_cnt - 1;
}


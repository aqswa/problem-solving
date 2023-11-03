//
// Created by LG on 2023-11-02.
//
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e9;
int V;
vector<vector<ci>> graph;
vector<int> end_nodes;


int find_longest(int s, int before){

    int longest = 0;
    for(int i=0; i<graph[s].size(); i++){
        int next = graph[s][i].first;
        int next_weight = graph[s][i].second;
        if(next == before)
            continue;
        int length = find_longest(next, s);
        if(length + next_weight > longest)
            longest = length + next_weight;
    }

    return longest;
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

    for(int i=1; i<=V; i++){
        if(graph[i].size() == 1){
            end_nodes.emplace_back(i);
        }
    }

    int ans = 0;
    for(int i=0; i<end_nodes.size(); i++){
        int a = find_longest(end_nodes[i], 0);
        if(a > ans)
            ans = a;
    }

    cout << ans;
}


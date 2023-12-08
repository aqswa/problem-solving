//
// Created by LG on 2023-12-08.
//
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 10000000

using namespace std;

bool gate[50001];
bool summit[50001];
vector<vector<pair<int, int>>> graph;
vector<int> intensity;

void find_intensity(int s){
    queue<int> q; //정점, 최대 난이도

    intensity[s] = 0;
    q.push(s);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int cur_intensity = intensity[node];
        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i].first; //연결된 정점
            int next_intensity = graph[node][i].second;
            if(gate[next]) //연결된 정점이 출입구라면 넘어감
                continue;
            if(cur_intensity < next_intensity){ //새로운 난이도가 더 크다면
                if(intensity[next] > next_intensity){ //다음 정점 난이도가 현재 정점에서 가는 난이도보다 높다면 갱신
                    intensity[next] = next_intensity;
                    if(!summit[next]){
                        q.push(next);
                    }
                }
            }
            else{
                if(intensity[next] > cur_intensity){
                    intensity[next] = cur_intensity;
                    if(!summit[next]){
                        q.push(next);
                    }
                }
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    graph.assign(n+1, vector<pair<int, int>>());
    intensity.assign(n+1, INF);

    for(int i=0; i<paths.size(); i++){
        int u = paths[i][0];
        int v = paths[i][1];
        int w = paths[i][2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for(int i=0; i<gates.size(); i++){
        gate[gates[i]] = true;
    }

    for(int i=0; i<summits.size(); i++){
        summit[summits[i]] = true;
    }

    for(int i=0; i<gates.size(); i++){
        find_intensity(gates[i]);
    }

    sort(summits.begin(), summits.end());
    answer.push_back(summits[0]);
    answer.push_back(intensity[summits[0]]);
    for(int i=1; i<summits.size(); i++){
        if(intensity[summits[i]] < answer[1]){
            answer[0] = summits[i];
            answer[1] = intensity[summits[i]];
        }
    }

    return answer;
}

int main(){
    int n = 7;
    vector<vector<int>> paths = {{1, 4, 4}, {1, 6, 1}, {1, 7, 3}, {2, 5, 2}, {3, 7, 4}, {5, 6, 6}};
    vector<int> gates = {1};
    vector<int> summits = {2, 3, 4};
    solution(n, paths, gates, summits);
}

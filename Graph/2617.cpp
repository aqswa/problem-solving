//
// Created by LG on 2024-02-03.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> graph;
int main() {
    cin >> N >> M;

    graph.assign(N+1, vector<int>());
    for(int i=0; i<M; i++){
        int a, b; //무거운 애, 가벼운 애
        cin >> a >> b;
        graph[a].push_back(b);
    }

    //int count[100][2]; //0: 내가 도달 가능한 노드 수(가벼운 구슬 수), 1: 나에 도달할 수 있는 노드 수(무거운 구슬 수)
    //memset(count, 0, sizeof(count));
    vector<vector<int>> count(100, vector<int>(2, 0));
    for(int i=1; i<=N; i++){
        queue<int> q;
        q.push(i);
        bool visited[100] = {false};
        visited[i] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int j = 0; j < graph[cur].size(); j++) {
                int next = graph[cur][j];
                if (!visited[next]) {
                    count[i][0]++;
                    count[next][1]++;
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        if(count[i][0] > N/2 || count[i][1] > N/2){
            //cout << i << " " << count[i][0] << ' ' << count[i][1] << '\n';
            ans++;
        }
    }

    cout << ans;
}

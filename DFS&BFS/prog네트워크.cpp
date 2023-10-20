//
// Created by LG on 2023-10-20.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<int> visited(n, false);

    for(int i=0; i<n; i++){
        if(visited[i])
            continue;

        queue<int> q;
        q.push(i);
        visited[i] = true;
        answer++;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int j=0; j<n; j++){
                if(computers[cur][j] && !visited[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }


    return answer;
}

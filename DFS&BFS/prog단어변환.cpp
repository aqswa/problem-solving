//
// Created by LG on 2023-10-20.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool adjacent(string s1, string s2){
    int cnt = 0;
    for(int i=0; i<s1.size(); i++){
        if(s1[i] != s2[i])
            cnt++;
    }

    if(cnt == 1)
        return true;
    else
        return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = words.size();

    int idx = -1;
    for(int i=0; i<words.size(); i++){
        if(words[i] == target)
            idx = i+1;
    }

    if(idx == -1) //words에 target 단어가 없다면 false 반환
        return 0;

    vector<vector<int>> graph(n+1, vector<int>());
    for(int i=0; i<n; i++){
        if(adjacent(begin, words[i]))
            graph[0].push_back(i+1); //0행이 begin, 1~n행이 주어진 단어들의 인접 노드 벡터
    }

    //인접 리스트 그래프
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adjacent(words[i], words[j])){
                graph[i+1].push_back(j+1);
            }
        }
    }

    queue<int> q;
    vector<int> distance(n+1, 51);
    vector<bool> visited(n+1, false);

    q.push(0); //begin 노드 push
    distance[0] = 0;
    visited[0] = true;
    while(!q.empty()){
        int c = q.front();
        q.pop();

        for(int i=0; i<graph[c].size(); i++){
            int next = graph[c][i];
            if(!visited[next]){
                visited[next] = true;
                distance[next] = distance[c] + 1;
                q.push(next);
            }
        }
    }

    answer = distance[idx];

    return answer;
}

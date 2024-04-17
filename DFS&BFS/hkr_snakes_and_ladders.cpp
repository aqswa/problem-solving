#include <bits/stdc++.h>

using namespace std;

// 더 빨리 도달하는 경우를 찾아야 하므로 dfs X
// void dfs(int square, int cnt) {
//     if(square >= 100) {
//         if(square == 100) {
//             if(cnt < answer) {
//                 answer = cnt;
//             }
//             cout << cnt << ' ';
//         }
//         return;
//     }

//     for(int i=6; i>=1; i--) {
//         int next = square + i;
//         if(!visited[next]) {
//             visited[next] = true;
//             if(ladder_map.find(next) != ladder_map.end()) {
//                 next = ladder_map[next];
//             }
//             if(snake_map.find(next) != snake_map.end()) {
//                 next = snake_map[next];
//             }
//             dfs(next, cnt + 1);
//         }
//     }
// }

int bfs(map<int, int> ladder_map, map<int, int> snake_map) {
    vector<bool> visited(101, false);
    visited[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    
    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == 100) {
            return cnt;
        }
        
        for(int i=1; i<=6; i++) {
            int next = cur + i;
            
            if(ladder_map.find(next) != ladder_map.end()) {
                next = ladder_map[next];
            }
            
            if(snake_map.find(next) != snake_map.end()) {
                next = snake_map[next];
            }
            
            if(!visited[next] && next <= 100) {
                visited[next] = true;
                q.push({next, cnt + 1});
            }
        }
    }
            
    return -1;
}

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    
    map<int, int> ladder_map;
    map<int, int> snake_map;

    for(int i=0; i<ladders.size(); i++) {
        ladder_map.insert({ladders[i][0], ladders[i][1]});
    }

    for(int j=0; j<snakes.size(); j++) {
        snake_map.insert({snakes[j][0], snakes[j][1]});
    }

    return bfs(ladder_map, snake_map);
}

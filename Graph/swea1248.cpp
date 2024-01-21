//
// Created by LG on 2024-01-21.
//
#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int V, E, V1, V2;
int parent[10001];
vector<vector<int>> tree;

int find_common(){
    set<int> s;
    int vertex = V1;
    while(vertex != -1){
        s.insert(vertex);
        vertex = parent[vertex];
    }

    vertex = V2;
    while(true){
        if(s.find(vertex) != s.end()){
            return vertex;
        }
        else{
            vertex = parent[vertex];
        }
    }
}

int find_size(int vertex){
    if(tree[vertex].size() == 0)
        return 1;
    else if(tree[vertex].size() == 1)
        return find_size(tree[vertex][0]) + 1;
    else
        return find_size(tree[vertex][0]) + find_size(tree[vertex][1]) + 1;
}

int main(){
    int T;
    cin >> T;

    for(int t=1; t<=T; t++){
        cin >> V >> E >> V1 >> V2;

        tree.assign(V+1, vector<int>());
        memset(parent, -1, sizeof(parent));
        for(int i=0; i<E; i++){
            int p, c;
            cin >> p >> c;
            parent[c] = p;
            tree[p].push_back(c);
        }

        int common = find_common();
        int tree_size = find_size(common);

        cout << "#" << t << ' ' << common << ' ' << tree_size << '\n';
    }
}

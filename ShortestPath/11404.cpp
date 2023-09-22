//
// Created by LG on 2023-09-22.
//
#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9; //최대 10억
int n;

void floyd(vector<vector<int>> &graph){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){ //노드 1->2로 가는 것과 노드 2->1로 가는 비용은 다르기 때문에 모든 반복문을 0부터 n-1까지 돈다.
               if(graph[j][i] + graph[i][k] < graph[j][k])
                   graph[j][k] = graph[j][i] + graph[i][k];
            }
        }
    }
}

int main(){
    int m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    //자기 자신으로 가는 거리는 초기화해야 한다.
    for(int i=0; i<n; i++)
        graph[i][i] = 0;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(graph[a-1][b-1] > c) //시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다고 했으므로 가장 짧은 노선을 입력받아야 함.
            graph[a-1][b-1] = c; //입력에서 도시는 1부터 100인데 0부터 99로 저장함.
    }

    floyd(graph);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j] == INF)
                cout << "0" << ' ';
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}

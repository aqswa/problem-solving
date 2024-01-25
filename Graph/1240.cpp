#include <iostream>
#include <vector>

using namespace std;

int N, M; //노드 개수, 알고 싶은 노드 쌍 개수
//vector<vector<pair<int, int>>> tree;
vector<vector<int>> dist;

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (dist[j][i] + dist[i][k] < dist[j][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    //tree.assign(N + 1, vector<pair<int, int>>());
    dist.assign(N + 1, vector<int>(N + 1, 1e9));
    for (int i = 0; i < N-1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        //tree[a].push_back({ b, w });
        dist[a][b] = w;
        dist[b][a] = w;
    }

    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    solve();
    while (M--) {
        int a, b;
        cin >> a >> b;

        cout << dist[a][b] << '\n';
    }
}
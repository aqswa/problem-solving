#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int tree[100001][2];
int cnt = 0;

int child(int node) { //자신 포함 자식 노드의 개수
	if (tree[node][0] > 0 && tree[node][1] > 0) {
		return child(tree[node][0]) + child(tree[node][1]) +1;
	}
	else if (tree[node][0] > 0 && tree[node][1] == -1) {
		return child(tree[node][0]) +1;
	}
	else if (tree[node][0] == -1 && tree[node][1] > 0) {
		return child(tree[node][1]) +1;
	}
	else {
		return 1;
	}
}

void solve(int node) {

	if (tree[node][0] != -1) { //왼쪽 노드가 있다면
		cnt += 2 * (child(tree[node][0]));
	}

	if (tree[node][1] != -1) { //오른쪽 노드가 있다면
		cnt += 1;
		solve(tree[node][1]);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a][0] = b;
		tree[a][1] = c;
	}

	solve(1);

	cout << cnt;
}

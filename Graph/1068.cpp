#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int N;
vector<vector<int>>tree;

int count_leaf(int node) {
	if (tree[node].size() == 0)
		return 1;
	else {
		int cnt = 0;
		for (int i = 0; i < tree[node].size(); i++) {
			cnt += count_leaf(tree[node][i]);
		}
		return cnt;
	}
}

int main() {
	
	cin >> N;

	vector<int> parent(N, -1);
	tree.assign(N, vector<int>());

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		parent[i] = p;
		if (p != -1) {
			tree[p].push_back(i);
		}
	}

	int total_leaf = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i].size() == 0) {
			total_leaf++;
		}
	}

	int node = 0;
	cin >> node;
	int removed = count_leaf(node); //없어진 리프 노드 수

	if (parent[node] != -1 && tree[parent[node]].size() == 1) { //루트 노드 지운게 아니고, 지운 노드의 자식 노드 개수가 1개였다면
		cout << total_leaf - removed + 1; //지운 노드가 리프 노드가 됨
	}
	else {
		cout << total_leaf - removed;
	}
}

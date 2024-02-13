#include <iostream>
#include <vector>

using namespace std;

int boss[100001];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		boss[i] = a;
	}

	vector<long long> ack(n + 1, 0);
	vector<int> input(n + 1, 0);
	while (m--) {
		int i, w;
		cin >> i >> w;
		input[i] += w;
	}

	cout << ack[1] << ' ';
	for (int i = 2; i <= n; i++) {
		ack[i] = ack[boss[i]] + input[i];
		cout << ack[i] << ' ';
	}
}

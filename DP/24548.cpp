#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

//출처: https://burningfalls.github.io/algorithm/boj-24548/
int N;
int main() {

	cin >> N;

	int ans = 0;
	int dp[3][3][3][3];
	memset(dp, 0, sizeof(dp));
	int t = 0, g = 0, f = 0, p = 0;

	dp[0][0][0][0] = 1; //나머지가 0인 지점이 처음으로 등장해도 구간의 시작점이 1인 경우 3의 배수 개 존재하므로
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		if (c == 'T') {
			t = (t + 1) % 3;
		}
		else if (c == 'G') {
			g = (g + 1) % 3;
		}
		else if (c == 'F') {
			f = (f + 1) % 3;
		}
		else {
			p = (p + 1) % 3;
		}

		ans += dp[t][g][f][p]; //나머지가 같은 지점 사이 구간들은 모두 3의 배수 개 존재하는 구간
		dp[t][g][f][p] += 1; //나도 나머지가 t, g, f, p인 지점
	}
	

	cout << ans;
}

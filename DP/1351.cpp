#include <iostream>
#include <map>

using namespace std;

long long N, P, Q;

// 실제 저장된 요소의 수가 적고 인덱스의 범위가 클 때는 map이 메모리 효율적
map<long long, long long> dp;

long long find(long long n) {
    if(dp.find(n) != dp.end()) {
        return dp[n];
    }

    return dp[n] = find(n/P) + find(n/Q);
}


int main() {
    cin >> N >> P >> Q;

    dp.insert({0, 1});
    cout << find(N);
}

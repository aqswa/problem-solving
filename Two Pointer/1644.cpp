//
// Created by LG on 2024-06-03.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<bool> is_prime(N+1, true);
    is_prime[1] = false;
    for(int i=2; i<=sqrt(N); i++) {
        if(is_prime[i]) {
            for (int j = i*2; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int cnt = 0;
    int s = 2, e = 2;
    int cur = 2;

    while(s <= N && e <= N) {
        if(cur < N) {
            while(cur < N && e < N) {
                e++;
                if(is_prime[e]) {
                    cur += e;
                }
            }

            if(e == N && cur < N) {
                break;
            }

        } else if(cur > N) {
            while(cur > N && s < e) {
                if(is_prime[s]) {
                    cur -= s;
                }
                s++;
            }

            if(cur > N && s == e) {
                break;
            }
        } else { //현재 합이 N과 같은 경우
            cnt++;

            if(e == N) break;

            while(e < N) {
                e++;
                if(is_prime[e]) {
                    cur += e;
                    break;
                }
            }

            if(e == N && !is_prime[e]) break;
        }
    }

    cout << cnt;
}
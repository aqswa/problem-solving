//
// Created by LG on 2023-03-03.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve(int n, int k){

    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    int cnt = 0;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            for(int j=i; j<=n; j+=i){
                if(is_prime[j]){
                    is_prime[j] = false;
                    cnt ++;
                    if(cnt == k)
                        return j;
                }
            }
        }
    }
    return 0;
}

int main() {

    int n, k;
    cin >> n >> k;

    cout << solve(n, k);

    return 0;
}

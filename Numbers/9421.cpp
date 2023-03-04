//
// Created by LG on 2023-03-04.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX=1000001;

void getPrime(vector<bool> &prime){
    prime[0] = prime[1] = false;
    for(int i=2; i<sqrt(MAX); i++){
        if(prime[i]){
            for(int j=i*2; j<MAX; j+=i){
                prime[j] = false;
            }
        }
    }
}

bool sangeun(int n){
    vector<bool> check(1000, false);

    while(true){
        int next = 0;
        while(n){
            next += pow(n%10, 2);
            n /= 10;
        }
        if(next == 1)
            return true;
        if(check[next])
            return false;
        else{
            check[next] = true;
            n = next;
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<bool> prime(MAX, true);
    getPrime(prime); //에라토스테네스의 체로 MAX 이하의 소수를 구함.

    for(int i=2; i<=n; i++){
        if(prime[i]){
            if(sangeun(i))
                cout << i << '\n';
        }
    }

    return 0;
}

//
// Created by LG on 2023-03-03.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX=1299710;

void getPrime(vector<bool> &prime){
    prime[0] = prime[1] = false;

    for(int i=2; i<sqrt(MAX); i++){
        if(prime[i]){
            for(int j=i*2; j<=MAX; j+=i){
                prime[j] = false;
            }
        }
    }

}

int main() {

    int t;
    cin >> t;

    vector<bool> prime(MAX, true);
    getPrime(prime);
    while(t--){

        int k;
        cin >> k;

        if(prime[k]) {
            cout << 0 << '\n';
        }
        else{
            int len = 1;
            int index = k;
            while(!prime[--index])
                len++;
            index = k;
            while(!prime[++index])
                len++;
            cout << len+1 << '\n';
        }

    }
}

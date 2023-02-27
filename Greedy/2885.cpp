//
// Created by LG on 2023-02-27.
//
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int k;
    cin >> k;

    int choco;
    for(int i=0; i<22; i++){
        if(pow(2, i) >= k){
            choco = pow(2, i);
            break;
        }
    }

    int cnt = 0;
    int temp = choco;

    while(k != 0) {
        while(k < temp){
            temp /= 2;
            cnt++;
        }
        k -= temp;
    }

    cout << choco << ' ' << cnt;
}

//
// Created by LG on 2023-01-19.
//
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long factorial = 1;
    int cnt = 0;

    for(int i=2; i<=n; i++){
        int mul = i;
        while(mul%5 == 0){
            cnt++;
            mul /= 5;
        }
    }

    cout << cnt;
}

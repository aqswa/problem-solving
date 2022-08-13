//
// Created by LG on 2022-03-05.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int M = 1000000;

int main(){

    int n, m;
    string s;
    cin >> n >> m >> s;

    int x = 2;
    int pattern = 0;
    for(int i=0; i<2*n+1; i++){
        if(i%2 == 0)
            pattern += 'I'*pow(x, i);
        else
            pattern += 'O'*pow(x, i);
        pattern %= M;
        cout << pattern << '\n';
    }

    int s0 = 0;
    for(int i=0; i<2*n+1; i++){
        s0 += s[i]*pow(x, i);
        s0 %= M;
        cout << "s0: " << s0 << '\n';
    }

    int cnt = 0;
    int s1 = 0;
    for(int i=2*n+1; i<m; i++){
        s1 = (s0-s[i-(2*n+1)]*pow(x, n-1))*x + s[n];
        if(s0 == pattern)
            cnt++;
        s0 = s1;
        cout << "s1: " << s1 << '\n';
    }

    cout << cnt;

}

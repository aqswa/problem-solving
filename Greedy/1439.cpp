//
// Created by LG on 2024-06-02.
//
#include <iostream>

using namespace std;

int main() {

    string s;
    cin >> s;

    int zero = 0, one = 0;
    int prev = 0;
    if(s[0] == '0') {
        prev = 0;
        zero++;
    } else {
        prev = 1;
        one++;
    }

    for(int i=1; i<s.length(); i++) {
        if(s[i]-'0' != prev) {
            prev = s[i] - '0';
            prev == 0 ? zero++ : one++;
        }
    }

    cout << (zero > one ? one : zero);
}

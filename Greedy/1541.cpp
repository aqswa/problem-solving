//
// Created by LG on 2024-06-01.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {

    string s;
    cin >> s;

    int total = 0;
    bool flag = false;

    for(int i=0; i<s.length(); i++) {
        int num = 0;
        while(i < s.length() && s[i] != '-' && s[i] != '+') {
            num *= 10;
            num += s[i] - '0';
            i++;
        }

        if(flag) {
            total -= num;
        } else {
            total += num;
        }

        if(i < s.length() && s[i] == '-'){
            flag = true;
        }
    }

    cout << total;
}

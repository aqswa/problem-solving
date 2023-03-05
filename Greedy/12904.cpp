//
// Created by LG on 2023-03-05.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int b_len = b.length();

    for(int i=b_len-1; i>=a.length(); i--){
        if(b[i] == 'A'){
            b = b.substr(0, i);
            if(b == a){
                cout << 1;
                return 0;
            }
        }
        else if(b[i] == 'B'){
            b = b.substr(0, i);
            reverse(b.begin(), b.end());
            if(b == a){
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;
    return 0;
}
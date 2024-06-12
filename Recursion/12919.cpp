//
// Created by LG on 2024-06-12.
//
#include <iostream>
#include <algorithm>

using namespace std;

bool answer = false;

void recursive(string s, string t) {
    if(s.length() == t.length()) {
        if(s == t) {
            answer = true;
        }
        return;
    }

    if(t[0] == 'B') {
        string next = t.substr(1, t.length()-1);
        reverse(next.begin(), next.end());
        recursive(s, next);
        if(answer){
            return;
        }
    }

    if(t[t.length()-1] == 'A') {
        string next = t.substr(0, t.length()-1);
        recursive(s, next);
        if(answer) {
            return;
        }
    }
}

int main() {
    string s, t;
    cin >> s >> t;

    recursive(s, t);
    cout << (answer ? 1 : 0);

}

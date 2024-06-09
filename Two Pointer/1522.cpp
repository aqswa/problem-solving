//
// Created by LG on 2024-06-09.
//
#include <iostream>
#include <vector>

using namespace std;

/*
vector<bool> check;
string s;
bool flag = false;

bool check_continuity(string s) {
    int cnt = 0;
    if(s[0] != s[s.length()-1]) {
        cnt++;
    }

    for(int i=0; i<s.length()-1; i++) {
        if(s[i] != s[i+1]) {
            cnt++;
        }
        if(cnt > 2) {
            return false;
        }
    }

    return true;
}

void choose_b(int goal, int cnt, int idx) {
    if(goal == cnt) {
        string temp = s;
        for(int i=0; i<check.size(); i++) {
            if(check[i]) {
                temp[i] = temp[i] == 'a' ? 'b' : 'a';
            }
        }
        if(check_continuity(temp)) {
            flag = true;
        }
        return;
    }

    for(int i=idx; i<s.length(); i++) {
        if(s[i] == 'b') {
            check[i] = true;
            choose_b(goal, cnt+1, i+1);
            if(flag) {
                break;
            }
            check[i] = false;
        }
    }
}

void choose_a(int goal, int cnt, int idx) {
    if(cnt == goal) {
        choose_b(goal, 0, 0);
        return;
    }

    for(int i=idx; i<s.length(); i++) {
        if(s[i] == 'a') {
            check[i] = true;
            choose_a(goal, cnt+1, i+1);
            if(flag) {
                break;
            }
            check[i] = false;
        }
    }
}

int main() {
    cin >> s;

    check.assign(s.length(), false);

    for(int i=0; i<s.length(); i++) {
        choose_a(i, 0, 0);
        if(flag) {
            cout << i;
            break;
        }
    }
}*/

//! ababbba같은 문자열에서 연속된 a와 b 만드는 최소 교환은 a의 개수 길이의 window에서 가장 적은 b의 개수

int main() {
    string s;
    cin >> s;

    int a_cnt = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'a'){
            a_cnt++;
        }
    }

    int answer = a_cnt;
    for(int i=0; i<s.length(); i++) {
        int cnt = 0;
        for(int j=0; j<a_cnt; j++) {
            int idx = (i + j) % (s.length());
            if(s[idx] == 'b') {
                cnt++;
            }
        }
        if(cnt < answer) {
            answer = cnt;
        }
    }

    cout << answer;
}


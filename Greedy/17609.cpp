//
// Created by LG on 2023-03-07.
//
#include <iostream>

using namespace  std;

int solve(string str){
    int flag = 0;
    int s = 0, e = str.length()-1;

    while(true) {
        if(s >= e){
            return flag;
        }

        if (str[s] == str[e]) {
            s++;
            e--;
            continue;
        }

        if (str[s + 1] == str[e] && flag == 0) {
            if(s+1 == e){
                flag = 1;
                return flag;
            }
            else if (str[s + 2] == str[e - 1]) {
                flag = 1;
                s += 3;
                e -= 2;
                continue;
            }
        }

        if (str[s] == str[e - 1] && flag == 0) {
            if(s == e-1){
                flag = 1;
                return flag;
            }
            else if (str[s + 1] == str[e - 2]) {
                flag = 1;
                s += 2;
                e -= 3;
            } else {
                flag = 2;
                return flag;
            }
        }
        else{
            flag = 2;
            return flag;
        }
    }
}

int main(){
    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
}


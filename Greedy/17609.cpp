//
// Created by LG on 2023-03-07.
//
#include <iostream>

using namespace std;

int solve(string str){
    int flag = 0;
    int s = 0, e = str.length()-1;

    for(int i=0; i<=e/2; i++){
        if(str[i] != str[e-i]){
            s = i;
            flag = 1;
            break;
        }
    }

    if(flag){
        e -= s;
        int mid = (e-s)/2;
        for(int i=0; i<mid; i++){
            if(str[s+i+1] != str[e-i]){
                flag = 2;
                break;
            }
        }

        if(flag == 2){
            for(int i=0; i<mid; i++){
                if(str[s+i] != str[e-i-1]){
                    flag = 2;
                    break;
                }
                flag = 1;
            }
        }
    }

    return flag;
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


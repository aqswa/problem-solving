//
// Created by LG on 2023-03-01.
//
#include <iostream>
#include <string>

using namespace std;


int main() {
    int t;
    cin >> t;

    while(t--){
        string str;
        cin >> str;

        bool symmetric = true;
        int len = str.length();
        while(len > 1){ // 1/2가 대칭이었다면 1/2의 절반인 1/4가 대칭이면 나머지 절만 1/4도 대칭이 됨.
            for(int i=0; i<len/2; i++){
                if(str[i] == str[len-1-i])
                    symmetric = false;
            }
            len /= 2;
        }

        if(symmetric)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

}

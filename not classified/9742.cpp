//
// Created by LG on 2022-05-10.
//
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
string s;
bool flag;

void FindPermutation(int a, string s2, vector<bool> &check) {
    if (s2.length() == s.length()){
        cnt++;
        if(a == cnt) {
            cout << s << ' ' << a << " = " << s2 << '\n';
            flag = true;
        }
        return;
    }
    for(int i=0; i<s.length(); i++){
        if(!check[i] && !flag) {
            check[i] = true;
            FindPermutation(a,s2+s[i], check);
            check[i] = false;
        }
    }
}

int main(){
    int a = 0;
    while(cin >> s >> a){
        string s2;
        flag = false;
        cnt = 0;
        vector<bool> check(s.length(), false);
        FindPermutation(a, s2, check);
        if(!flag)
            cout << s << ' ' << a << " = No permutation" << '\n';
    }
}

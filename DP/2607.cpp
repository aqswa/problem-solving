//
// Created by LG on 2022-03-16.
//
#include <iostream>
#include <vector>

using namespace std;

bool isSimilar(string a, string b){
    //길이가 짧은 문자열이 a
    if(a.length() > b.length()){
        string temp = a;
        a = b;
        b = temp;
    }

    vector<bool> b_check(b.length(), false); //길이 먼저 할당한다.

    for(char c : a){
        for(int j=0; j<b.length(); j++){
            if(c == b[j] && !b_check[j]){
                b_check[j] = true;
                break;
            }
        }
    }

    int cnt = 0;
    for(int i : b_check){
        if(!i)
            cnt++;
    }

    if(cnt > 1)
        return false;
    else
        return true;

}

int main(){

    int n;
    cin >> n;
    n--;
    string str;
    cin >> str;

    int cnt = 0;
    while(n--){
        string new_str;
        cin >> new_str;

        if(str.length()+1 < new_str.length() || str.length()-1 > new_str.length())
            continue;

        if(isSimilar(str, new_str))
            cnt++;
    }

    cout << cnt;
}

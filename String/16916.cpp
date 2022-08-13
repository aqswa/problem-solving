//
// Created by LG on 2022-03-07.
//
#include <iostream>

using namespace std;

const int M = 1000000000;

bool isSubstring(string s, string p){

    int slen = s.length();
    int plen = p.length();

    int keyVal = 0;
    int hashVal = 0;
    int power = 1;

    for(int i=0; i<=slen-plen; i++){
        if(i==0){
            for(int j=plen-1; j>=0; j--){
                hashVal += s[j]*power;
                keyVal += p[j]*power;
                power *= 3;
                //hashVal %= M;
                //keyVal %= M;
            }
            power /= 3;
        }
        else{
            hashVal = 3*(hashVal-s[i-1]*power)+s[p.length()+i-1];
            //hashVal %= M;
        }

        //cout << keyVal << ' ' << hashVal << '\n';

        if(hashVal == keyVal){
            bool flag = true;
            for(int j=0; j<p.length(); j++){
                if(p[j] != s[i+j])
                    flag = false;
            }
            if(flag)
                return true;
        }
    }
    return false;
}

int main(){

    string s, p;
    cin >> s >> p;

    cout << isSubstring(s, p);

    return 0;
}

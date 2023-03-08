//
// Created by LG on 2023-03-08.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long n;
    cin >> n;

    vector<int> count(10, 0);

    while(n > 0){
        count[n%10]++;
        n /= 10;
    }

    if(count[6] > count[9]){
        if((count[6]-count[9])%2 == 0)
            count[6] = count[9] + (count[6]-count[9])/2;
        else
            count[6] = count[9] + (count[6]-count[9])/2 + 1;
    }
    else{
        if((count[9]-count[6])%2 == 0)
            count[9] = count[6] + (count[9]-count[6])/2;
        else
            count[9] = count[6] + (count[9]-count[6])/2 + 1;
    }

    int max = 0;
    for(int i=0; i<10; i++){
        if(count[i] > max){
            max = count[i];
        }
    }

    cout << max;
}

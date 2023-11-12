//
// Created by LG on 2023-11-12.
//
#include <iostream>
#include <vector>
//#include <cstdio>

using namespace std;

int main(){

    //freopen("input.txt", "r", stdin);

    for(int i=1; i<=10; i++){
        int n; //건물 개수
        cin >> n;
        cout << "#" << i << ' ';

        vector<int> buildings(n, 0);
        vector<int> cantsee(n, 0);
        for(int j=0; j<n; j++){
            cin >> buildings[j];
        }

        for(int j=2; j<n-2; j++){
            cantsee[j] = buildings[j-2];
            if(cantsee[j] < buildings[j-1])
                cantsee[j] = buildings[j-1];
            if(cantsee[j] < buildings[j+1])
                cantsee[j] = buildings[j+1];
            if(cantsee[j] < buildings[j+2])
                cantsee[j] = buildings[j+2];
        }

        int total_cnt = 0;
        for(int j=2; j<n-2; j++){
            int cnt = buildings[j] - cantsee[j];
            if(cnt > 0)
                total_cnt += cnt;
        }

        cout << total_cnt << '\n';
    }
}
//
// Created by LG on 2022-03-08.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first-a.second > b.first-b.second; //맛의 차이가 큰 순으로 내림차순 정렬
}

int main(){

    int n, x;
    cin >> n >> x;
    int cost = 1000*n;
    int total = 0;

    vector<pair<int, int>> taste;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        taste.emplace_back(a, b);
        total += b;
    }

    sort(taste.begin(), taste.end(), cmp);

    for(int i=0; i<taste.size(); i++){
        cost += 4000;
        if(cost > x)
            break;
        if(taste[i].first > taste[i].second) {
            total -= taste[i].second;
            total += taste[i].first;
        }
    }

    cout << total;
}
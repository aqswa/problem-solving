//
// Created by LG on 2023-03-21.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq; //priority queue의 오름차순 정렬. (자료형, 컨테이너 자료형, 비교 방법)

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            pq.push(a);
            pq.pop();
        }
    }

    cout << pq.top();

}
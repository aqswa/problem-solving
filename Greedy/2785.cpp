//
// Created by LG on 2023-03-01.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> rings(n, 0);
    for(int i=0; i<n; i++)
        cin >> rings[i];

    sort(rings.begin(), rings.end());

    int shortest = 0;
    int cnt = 0;
    while(n != 1){
        if(rings[shortest] >= n-1) { //가장 짧은 체인이 연결해야될 구간 수보다 크거나 같다면
            cnt += n-1; //구간 수만큼 체인을 열었다가 닫고 끝냄.
            break;
        }
        else{
            n -= rings[shortest] + 1; //가장 짧은 체인이 연결해야될 구간 수보다 작다면 구간 연결하고 가장 짧은 체인 다씀
            cnt += rings[shortest];   //가장 짧은 체인이 길이가 3이었다면 (남은 체인 수 - 3 - 가장 짧은 체인 1개 소모)
        }
        shortest++; //가장 짧은 체인 인덱스 증가
    }

    cout << cnt;

    return 0;
}

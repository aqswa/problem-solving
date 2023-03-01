//
// Created by LG on 2023-03-01.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> price(n, 0);
        for(int i=0; i<n; i++)
            cin >> price[i];

        long long profit = 0, max = price[n-1]; //최대 주가를 마지막 날로 초기화
        for(int i=n-2; i>=0; i--){ //미래에서부터
            if(price[i] < max){ //오늘 주가가 미래의 최대 주가보다 낮다면
                profit += max-price[i]; //미래의 최대 주가인 날에 매도
            }
            else{
                max = price[i]; //오늘 주가가 미래의 최대 주가보다 높다면 최대 주가로 갱신
            }
        }

        cout << profit << '\n';
    }
}

//
// Created by LG on 2023-10-17.
//
#include <iostream>
#include <vector>

using namespace std;

int N;

int main(){
    cin >> N;
    vector<int> array(N, 0);
    for(int i=0; i<N; i++){
        cin >> array[i];
    }

    vector<int> dp(N, 0);
    dp[0] = 1;

    int max = 1; //가장 긴 수열의 길이
    for(int i=1; i<N; i++){
        int longest = 0; //이전 dp 중 가장 긴 수열. 나보다 작은 원소가 없을 수도 있으니까 1이 아닌 0으로 시작해야 함.
        for(int j=0; j<i; j++){
            if(array[j] < array[i] && dp[j] > longest)
                longest = dp[j];
        }
        dp[i] = longest + 1;
        if(dp[i] > max)
            max = dp[i];
    }

    cout << max;
}

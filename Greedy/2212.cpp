//
// Created by LG on 2023-03-12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> sensor(n, 0);
    for(int i=0; i<n; i++){
        cin >> sensor[i];
    }

    sort(sensor.begin(), sensor.end());

    int ans = sensor[n-1] - sensor[0];
    int last_index = 0;

    k--;
    while(k--){
        int min = ans;
        int index = last_index;
        for(int i=last_index+1; i<n; i++){
            int temp = ans;
            if(i == last_index+1){
                temp -= (sensor[n-1] - sensor[last_index] - 1);
                temp += (sensor[n-1] - sensor[i]);
            }
            else{
                temp -= (sensor[n-1] - sensor[last_index]);
                temp += (sensor[n-1] - sensor[i]) + (sensor[i-1] - sensor[last_index]);
            }

            cout << temp << ' ';
            if(temp <= min){
                min = temp;
                index = i;
            }
        }
        last_index = index;
        ans = min;
    }

    cout << ans;
}

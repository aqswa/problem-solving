//
// Created by LG on 2022-04-13.
//
#include <iostream>
#include <queue>

using namespace std;

int minTime(vector<int> truck, int width, int max_weight){

    int ans = truck.size() + width;
    queue<int> q;
    int sum = 0;

    for(int i=0; i<truck.size(); i++){
        q.push(truck[i]);
        sum += truck[i];
        while(sum >= max_weight){
            sum -= q.front();
            q.pop();
            ans++;
        }
    }
    return ans;
}

int main(){

    int n, w, l;
    cin >> n >> w >> l;

    vector<int> truck(n, 0);
    for(int i=0; i<n; i++) {
        cin >> truck[i];
    }

    cout << minTime(truck, w, l);
}

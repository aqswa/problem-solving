//
// Created by LG on 2022-03-08.
//회의실 배정 - 그리디

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, cnt = 1;
    cin >> n;

    vector<pair<int, int>> meeting_time(n, pair<int, int>());

    for(int i=0; i<n; i++)
        cin >> meeting_time[i].second >> meeting_time[i].first;

    sort(meeting_time.begin(), meeting_time.end());

    int end_time = meeting_time[0].first;
    for(int i=1; i<n; i++){
        if(meeting_time[i].first >= end_time && meeting_time[i].second >= end_time){
            end_time = meeting_time[i].first;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}



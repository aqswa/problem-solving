//
// Created by LG on 2023-09-16.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d_index = n-1;
    int p_index = n-1;

    while(d_index >= 0 && deliveries[d_index] == 0){ //! 가장 먼 집에 배달, 수거가 모두 0인 경우를 고려해야 함.
        d_index--;
    }
    while(p_index >= 0 && pickups[p_index] == 0){
        p_index--;
    }

    while(d_index >= 0 || p_index >= 0){
        if(d_index >= p_index){ //배달할 집이 더 멀리 있는 경우
            answer += 2 * (d_index + 1);
        }
        else{ //수거할 집이 더 멀리 있는 경우
            answer += 2 * (p_index + 1);
        }

        int cnt = 0; //지금 몇 개 실었는지
        for(int i=d_index; i>=0; i--){ //cap만큼 배달
            if(cnt + deliveries[i] <= cap){
                cnt += deliveries[i];
                d_index--;
            }
            else{
                deliveries[i] -= (cap - cnt);
                cnt = cap;
                break;
            }
        }

        cnt = 0;
        for(int i=p_index; i>=0; i--){ //cap만큼 수거
            if(cnt + pickups[i] <= cap){
                cnt += pickups[i];
                p_index--;
            }
            else{
                pickups[i] -= (cap - cnt);
                cnt = cap;
                break;
            }
        }
    }

    return answer;
}

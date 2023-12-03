//
// Created by LG on 2023-12-02.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long q1_sum = 0, q2_sum = 0;
    for(int i=0; i<queue1.size(); i++){
        q1_sum += queue1[i];
        q2_sum += queue2[i];
    }
    cout << q1_sum << ' ' << q2_sum << '\n';

    int q1_front = 0, q2_front = 0;

    while(true){
        if(q1_sum > q2_sum){
            if(q1_front >= queue1.size()){
                int q1_idx = q1_front % queue1.size();
                if(q1_idx >= q2_front)
                    return -1;
                q1_sum -= queue2[q1_idx];
                q2_sum += queue2[q1_idx];
                q1_front++;
            }
            else{
                //q1에서 하나 빼서 q2에 push함
                q1_sum -= queue1[q1_front];
                q2_sum += queue1[q1_front];
                q1_front++;
            }
        }
        else if(q1_sum < q2_sum){
            if(q2_front >= queue2.size()){
                int q2_idx = q2_front % queue1.size();
                if(q2_idx >= q1_front)
                    return -1;
                q2_sum -= queue1[q2_idx];
                q2_sum += queue1[q2_idx];
                q2_front++;
            }
            else{
                //q2에서 하나 빼서 q1에 push함
                q2_sum -= queue2[q2_front];
                q1_sum += queue2[q2_front];
                q2_front++;
            }
        }
        answer++;

        if(q1_sum == q2_sum){
            return answer;
        }
    }

}

int main(){
    vector<int> q1 = {1, 1};
    vector<int> q2 = {1, 5};
    solution(q1, q2);
}

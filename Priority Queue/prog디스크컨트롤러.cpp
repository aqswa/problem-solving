//
// Created by LG on 2023-10-21.
//
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(vector<int> v1, vector<int> v2){
        return v1[1] > v2[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cur = 0; //현재 시간
    priority_queue<vector<int>, vector<vector<int> >, compare> pq;

    sort(jobs.begin(), jobs.end()); //요청 시간 오름차순으로 정렬

    int total = 0;
    int cur_time = 0; //현재 시간
    int job_idx = 0; //남은 일들 중 첫 인덱스
    while(job_idx < jobs.size()){
        for(int i=job_idx; i<jobs.size(); i++){
            if(jobs[i][0] <= cur_time){
                pq.push(jobs[i]);
                job_idx++;
            }
            else{
                break;
            }
        }

        if(pq.empty() && job_idx < jobs.size()){
            cur_time = jobs[job_idx][0];
        }

        while(!pq.empty()){
            vector<int> cur_job = pq.top();
            pq.pop();
            cur_time += cur_job[1];
            total += cur_time - cur_job[0];
        }

    }

    answer = total / jobs.size();

    return answer;
}

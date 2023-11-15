//
// Created by LG on 2023-10-15.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int discount[4] = {90, 80, 70, 60};
int N;
int max_plus = 0;
int max_sell = 0;

void dfs(vector<vector<int>> users, vector<int> emoticons, int idx, vector<int> order){
    if(idx == N){
        int plus_cnt = 0;
        int total_sell = 0;
        for(int i=0; i<users.size(); i++){
            int total_price = 0;
            for(int j=0; j<emoticons.size(); j++){
                if(order[j] >= users[i][0]){ //할인율이 사용자 할인율보다 높다면
                    total_price += emoticons[j] * 0.01 * order[j];
                }
            }
            if(total_price >= users[i][1]){  //총 가격이 최소 이모티콘 플러스 가격보다 높다면
                plus_cnt++;
            }
            else{
                total_sell += total_price;
            }
        }

        if(plus_cnt >= max_plus){
            max_plus = plus_cnt;
            if(total_sell > max_sell)
                max_sell = total_sell;
        }

        return;
    }

    for(int i=idx; i<N; i++){
        for(int j=0; j<4; j++){
            order[i] = discount[j];
            dfs(users, emoticons, idx+1, order);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    N = emoticons.size(); //할인율 결정할 이모티콘의 개수
    vector<int> order(N+1, 0); //이모티콘의 할인율

    dfs(users, emoticons, 0, order);

    answer[0] = max_plus;
    answer[1] = max_sell;
    return answer;
}

int main(){

    vector<vector<int>> users = {{40, 10000}, {25, 10000}};
    vector<int> emoticons = {7000, 9000};

    vector<int> answer = solution(users, emoticons);
    cout << answer[0] << ' ' << answer[1];
    return 0;
}

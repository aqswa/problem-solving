//
// Created by LG on 2023-10-16.
//
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;

    int num = 0;
    vector<set<int>> dp(9); //set 활용하기
    for(int i=1; i<9; i++){ //N, NN, NNN, ..., NNNNNNNN
        num = num*10 + N;
        dp[i].insert(num);
    }

    for(int i=2; i<9; i++){
        for(int k=1; k<i; k++){
            for(int a : dp[k]){
                for(int b : dp[i-k]){
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(b != 0){
                        dp[i].insert(a/b);
                    }
                }
            }
        }
    }

    for(int i=1; i<9; i++){
        if(dp[i].find(number) != dp[i].end()){
            answer = i;
            break;
        }
    }


    return answer;
}

//
// Created by LG on 2023-12-05.
//
#include <string>
#include <vector>

#define INF 999999999

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int alp_goal = 0, cop_goal = 0; //달성해야하는 알고력, 코딩력
    for(int i=0; i<problems.size(); i++){
        if(problems[i][0] > alp_goal){
            alp_goal = problems[i][0];
        }
        if(problems[i][1] > cop_goal){
            cop_goal = problems[i][1];
        }
    }

    if(alp > alp_goal){ //현재 알고력이 달성해야할 알고력보다 높은 경우
        alp_goal = alp; //달성해야할 알고력을 현재 알고력으로
    }
    if(cop > cop_goal){
        cop_goal = cop;
    }

    vector<vector<int>> dp(alp_goal + 1, vector<int>(cop_goal + 1, INF));
    dp[alp][cop] = 0;

    for(int i=alp; i<=alp_goal; i++){
        for(int j=cop; j<=cop_goal; j++){
            if(i < alp_goal){ //i == alp_goal인 경우 빼고
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            }
            if(j < cop_goal){ //j == cop_goal인 경우 빼고
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            }
            for(int k=0; k<problems.size(); k++){
                int alp_req = problems[k][0];
                int cop_req = problems[k][1];
                int alp_rwd = problems[k][2];
                int cop_rwd = problems[k][3];
                int cost = problems[k][4];

                if(i < alp_req || j <cop_req){ //알고력이나 코딩력이 문제에 미치지 못함
                    continue;
                }
                int next_alp = min(i+alp_rwd, alp_goal);
                int next_cop = min(j+cop_rwd, cop_goal);
                dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost);
            }
        }
    }

    return dp[alp_goal][cop_goal];
}

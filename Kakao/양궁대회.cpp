#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
vector<int> INFO;
int max_diff = 0;
int N;

int compare(vector<int> choosed) {
    int apeach = 0;
    int lion = 0;
    for(int i=0; i<11; i++) {
        if(INFO[i] >= choosed[i]) {
            if(INFO[i] != 0) { //둘 다 0점인 경우는 점수 없음
                apeach += (10 - i);
            }
        } else {
            lion += (10 - i);
        }
    }
    
    return lion - apeach;
}

void combination(int score, int left, vector<int> choosed) {
    if(score == -1) {
        if(left == 0) {
            int diff = compare(choosed);
            if(max_diff < diff) {
                max_diff = diff;
                ans = choosed;
            }
        }
        return;
    }
    
    for(int i=left; i>=0; i--) { //점수차가 같은 경우, 낮은 점수가 더 많은 경우로
        choosed[score] = i;
        combination(score-1, left-i, choosed);
    }
}

vector<int> solution(int n, vector<int> info) {
    INFO = info; N = n;
    vector<int> choosed(11, 0); //10점 ~ 0점
    combination(10, N, choosed); //현재 쏘는 점수 인덱스, 남은 점수
    
    vector<int> loose = {-1};
    if(max_diff == 0) {
        return loose;
    }
    return ans;
}

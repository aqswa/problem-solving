//
// Created by LG on 2023-11-16.
//
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

vector<int> elements;
vector<int> num;
int N;
double ret = 0;

void backtracking(int cnt, int n, int start){ //선택한 원소 수, 최종 원소 수, 원소들 합
    if(cnt == n){
        double sum = 0;
        for(int i=0; i<cnt; i++){
            sum += num[i];
        }
        ret += sum / n;
        return;
    }

    for(int i=start; i<N; i++){
        num[cnt] = elements[i];
        backtracking(cnt+1, n, i+1);
    }
}

int main(){
    int t;
    cin >> t;

    for(int k=1; k<=t; k++){
        cin >> N;
        num.assign(N, 0);
        elements.assign(N, 0);
        for(int i=0; i<N; i++){
            cin >> elements[i];
        }

        cout << "#" << k << ' ';

        int partial_count = pow(2, N) - 1; //부분집합 개수
        double total = 0; //각 부분집합의 평균의 합
        for(int i=1; i<=N; i++){
            backtracking(0, i, 0);
            total += ret;
            ret = 0;
        }

        cout.precision(20);
        cout << total / partial_count << '\n';
    }
}

//
// Created by LG on 2023-03-08.
//
#include <iostream>
#include <vector>
#define MAX 1e9

using namespace  std;

int N;
string before, after;
int ans = MAX;

void solve(int first){
    int cnt = 0;
    string temp = before;
    if(first == 0){ //첫 번째 스위치를 누르는 경우
        temp[0] = (temp[0] == '0') ? '1' : '0';
        temp[1] = (temp[1] == '0') ? '1' : '0';
        cnt++;
    }

    for(int i=1; i<N; i++){
        if(temp[i-1] != after[i-1]){
            temp[i-1] = (temp[i-1] == '0') ? '1' : '0';
            temp[i] = (temp[i] == '0') ? '1' : '0';
            if(i != N-1){
                temp[i+1] = (temp[i+1] == '0') ? '1' : '0';
            }
            cnt++;
        }
    }

    if(temp == after){
        if(cnt < ans){
            ans = cnt;
        }
    }
}

int main(){
    cin >> N;
    cin >> before >> after;

    solve(0);
    solve(1);

    if(ans == MAX)
        cout << "-1";
    else
        cout << ans;

}

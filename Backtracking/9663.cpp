//
// Created by LG on 2023-03-20.
//
#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int n;
vector<int> board;

void recursion(int r){
    if(r==n+1){
        ans++;
        return;
    }

    for(int i=1; i<=n; i++){ //r번째 행에서 1~n칸까지 중 놓을 수 있는 칸 찾기
        bool flag = false;
        for(int j=1; j<r; j++){ //이미 퀸이 놓인 r-1번째 행까지의 정보 이용해서 놓을 수 있는 곳 찾기
            if(board[j] == i || abs(r-j) == abs(i-board[j])){
                flag = true;
                break;
            }
        }
        if(!flag){
            board[r] = i;
            recursion(r+1);
        }
    }
}

int main(){
    cin >> n;
    board.assign(n+1, 0);
    recursion(1);

    cout << ans;

}
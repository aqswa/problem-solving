//
// Created by LG on 2023-01-20.
//
#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int n, int src, int dst){
    if(n==1){  //종료조건: 원판이 하나 남았을 시 그냥 src에서 dst로 이동함
        cout << src << " " << dst << '\n';
        return;
    }
    int rest = 1; //src, dst가 아닌 나머지 기둥
    if(src==1){
        if(dst==2)
            rest = 3;
        else
            rest = 2;
    }
    else if(src==2){
        if(dst==1)
            rest = 3;
    }
    else{
        if(dst==1)
            rest = 2;
    }

    hanoi(n-1, src, rest);  //가장 밑 원판을 뺀 원판들을 src에서 나머지 기둥으로 이동

    cout << src << " " << dst << '\n'; //가장 밑 원판을 src에서 dst로 이동

    hanoi(n-1, rest, dst); // 나머지 기둥에서 dst로 이동
}

int main(){
    int n;
    cin >> n;

    cout << int(pow(2, n) - 1) << '\n'; //하노이 탑에서 원판의 이동 횟수는 원판이 1개이면 1, 2개이면 1*1+1, 3개이면 3*2+1 ...
    // (가장 밑 원판 제외한 원판들을 2번 이동하기(src->rest, rest->dst)) + (가장 밑 원판의 이동 횟수 1번)
    hanoi(n, 1, 3);
}

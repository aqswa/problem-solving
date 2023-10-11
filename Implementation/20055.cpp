//
// Created by LG on 2023-10-07.
//
#include <iostream>
#include <vector>
#include <algorithm>

int n, k;

using namespace std;

int main() {
    cin >> n >> k; //벨트 한쪽 길이
    vector<int> belt(2*n, 0);
    vector<bool> robot(2*n, false);
    int zero_cnt = 0; //내구도 0인 칸 개수
    int step_cnt = 1; //단계 수
    int start_idx = 0;

    //벨트 내구도 입력
    for(int i=0; i<2*n; i++){
        cin >> belt[i];
        if(belt[i] == 0)
            zero_cnt++;
    }

    while(true){
        // 1. 벨트 전체 한 칸 이동
        if(start_idx == 0)
            start_idx = 2*n-1;
        else
            start_idx--;
        int down_idx = (start_idx + n - 1) % (2*n);
        robot[down_idx] = false; // 내리는 위치에 있는 로봇 내림

        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동
        for(int i=1; i<=n; i++){ //벨트 한쪽 길이만큼
            int cur_idx = down_idx - i; //내리는 칸 이전 칸으로 한칸씩
            if(cur_idx < 0){
                cur_idx = 2*n + cur_idx;
            }
            int next_idx = (cur_idx + 1) % (2*n);
            if(robot[cur_idx] && !robot[next_idx] && belt[next_idx] > 0){ //로봇 이동할 수 있는 조건이라면
                robot[cur_idx] = false; //이동
                if(next_idx == down_idx) //이동한 칸이 내리는 칸이라면
                    robot[next_idx] = false;
                else
                    robot[next_idx] = true;
                belt[next_idx]--; //이동한 칸 내구도 감소
                if(belt[next_idx] == 0)
                    zero_cnt++;
            }
        }

        //3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if(belt[start_idx] != 0){ //올리는 위치 내구도 0 아니라면
            robot[start_idx] = true;
            belt[start_idx]--;
            if(belt[start_idx] == 0){
                zero_cnt++;
            }
        }

        //4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료
        if(zero_cnt >= k)
            break;

        step_cnt++;
    }

    cout << step_cnt;
}

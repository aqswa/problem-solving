//
// Created by LG on 2023-09-17.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101
using namespace std;

int board[MAX][MAX]; //array라는 변수명을 썼는데 reference to 'array' is ambiguous 컴파일 에러 뜸.

void row_sort(int &r, int &c){ //행 연산
    int max_col = 2; //최소 행 길이 2

    for(int i=0; i<r; i++) { //모든 행에 대하여
        vector<int> count(101, 0);
        vector<pair<int, int>> count_pair{};
        for(int j=0; j<c; j++){
            count[board[i][j]]++; //배열에 해당 숫자가 등장했음을 표시
        }
        for(int j=1; j<101; j++){ //0은 고려하지 않음
            if(count[j] != 0){ //숫자 j가 한번이라도 등장했다면
                count_pair.emplace_back(count[j], j); //등장한 횟수와 숫자
            }
        }

        sort(count_pair.begin(), count_pair.end()); //pair sort 디폴트가 first 오름차순, 같다면 second 오름차순

        for(int j=0; j<c; j++){ //행 크기가 커졌는지 작아졌는지 모르니 0으로 모두 초기화함
            board[i][j] = 0;
        }

        for(int j=0; j<count_pair.size(); j++){ //입력된 pair 정보들을 전역 변수로 선언된 board에 옮겨줌.
            board[i][j*2] = count_pair[j].second;
            board[i][j*2+1] = count_pair[j].first;
        }

        if(int(count_pair.size()) * 2 > max_col){ //저장된 페어 * 2가 현재 열 크기보다 길다면 최대 열 크기
            max_col = int(count_pair.size()) * 2;
        }
    }

    c = max_col;
}

void col_sort(int &r, int &c){
    int max_row = 2; //최소 열 크기는 2

    for(int i=0; i<c; i++) {
        vector<int> count(101, 0);
        vector<pair<int, int>> count_pair{};
        for(int j=0; j<r; j++){
            count[board[j][i]]++; //배열에 해당 숫자가 등장했음을 표시
        }
        for(int j=1; j<101; j++){ //0은 고려하지 않음
            if(count[j] != 0){ //숫자 j가 한번이라도 등장했다면
                count_pair.emplace_back(count[j], j); //등장한 횟수와 숫자 입력
            }
        }

        sort(count_pair.begin(), count_pair.end());

        for(int j=0; j<r; j++){ //행 크기가 커졌는지 작아졌는지 모르니 0으로 모두 초기화함
            board[j][i] = 0;
        }

        for(int j=0; j<count_pair.size(); j++){ //입력된 pair 정보들을 전역 변수로 선언된 board에 옮겨줌.
            board[j*2][i] = count_pair[j].second;
            board[j*2+1][i] = count_pair[j].first;
        }

        if(int(count_pair.size()) * 2 > max_row){ //저장된 페어 * 2가 현재 행 크기보다 길다면 최대 행 크기
            max_row = int(count_pair.size()) * 2;
        }
    }

    r = max_row;
}

int main(){
    int r, c, k, time;
    cin >> r >> c >> k; //r행 c열에 k가 들어있을 때까지 걸리는 시간
    int row = 3, col = 3; //처음 행의 크기는 3, 열의 크기는 3

    for(int i=0; i<3; i++){ //3x3 배열 입력 받음
        for(int j=0; j<3; j++){
            cin >> board[i][j];
        }
    }

    while(time <= 100) { //최대 100번까지 정렬함
        if(board[r-1][c-1] == k){
            cout << time;
            return 0;
        }
        if (row >= col) { //행의 개수 >= 열의 개수라면 R연산
            row_sort(row, col);
        } else {
            col_sort(row, col);
        }
        time++;
    }

    cout << "-1";

    return 0;
}

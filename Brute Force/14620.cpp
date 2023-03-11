//
// Created by LG on 2023-03-11.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> ground(n, vector<int>(n, 0)); //땅 가격 정보
    int ans = 3001;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ground[i][j];
        }
    }

    for(int i=1; i<n*n; i++){
        for(int j=i+1; j<n*n; j++){
            for(int k=j+1; k<n*n; k++){
                int f_row = i/n; //첫 번째 씨앗 row
                int f_col = i%n; //첫 번째 씨앗 col
                int s_row = j/n;
                int s_col = j%n;
                int t_row = k/n;
                int t_col = k%n;

                if(f_row < 1 || f_row > n-2 || f_col < 1 || f_col > n-2) //테두리에 위치하면 넘어감
                    continue;
                if(s_row < 1 || s_row > n-2 || s_col < 1 || s_col > n-2)
                    continue;
                if(t_row < 1 || t_row > n-2 || t_col < 1 || t_col > n-2)
                    continue;

                if(abs(f_row-s_row) + abs(f_col-s_col) < 3) //첫번째 씨앗과 두 번째 씨앗이 겹치면 넘어감
                    continue;
                if(abs(f_row-t_row) + abs(f_col-t_col) < 3) //첫번째와 세 번째 씨앗이 겹치면
                    continue;
                if(abs(s_row-t_row) + abs(s_col-t_col) < 3) //두 번째와 세 번째 씨앗이 겹치면
                    continue;

                //총 땅 가격
                int price = ground[f_row][f_col] + ground[f_row-1][f_col] + ground[f_row+1][f_col] + ground[f_row][f_col+1] + ground[f_row][f_col-1] +
                        ground[s_row][s_col] + ground[s_row-1][s_col] + ground[s_row+1][s_col] + ground[s_row][s_col+1] + ground[s_row][s_col-1] +
                        ground[t_row][t_col] + ground[t_row-1][t_col] + ground[t_row+1][t_col] + ground[t_row][t_col+1] + ground[t_row][t_col-1];

                if(price < ans) {
                    ans = price;
                }
            }
        }
    }

    cout << ans;
}

//
// Created by LG on 2023-12-26.
//
#include <iostream>
#define MIN -1e9;

using namespace std;

int arr1[21];
int arr2[21];

int main(){
    int T;
    cin >> T;

    for(int t=1; t<=T; t++){
        int N, M;
        cin >> N >> M;
        int ans = MIN;

        for(int i=0; i<N; i++){
            cin >> arr1[i];
        }

        for(int i=0; i<M; i++){
            cin >> arr2[i];
        }

        if(M > N) {
            for (int i = 0; i < M - N + 1; i++) {
                int sum = 0;
                for (int j = 0; j < N; j++) {
                    sum += arr1[j] * arr2[i + j];
                }
                if (sum > ans) {
                    ans = sum;
                }
            }
        }
        else{
            for (int i = 0; i < N - M + 1; i++) {
                int sum = 0;
                for (int j = 0; j < M; j++) {
                    sum += arr1[i + j] * arr2[j];
                }
                if (sum > ans) {
                    ans = sum;
                }
            }
        }

        cout << "#" << t << ' ' << ans << '\n';
    }
}

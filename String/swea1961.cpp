//
// Created by LG on 2023-12-26.
//
#include <iostream>

using namespace std;

int board[7][7];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int t=1; t<=T; t++){
        int N;
        cin >> N;
        cout << "#" << t << '\n';

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> board[i][j];
            }
        }

        for(int i=0; i<N; i++){
            for(int j=N-1; j>=0; j--){
                cout << board[j][i];
            }
            cout << ' ';

            for(int j=N-1; j>=0; j--){
                cout << board[N-1-i][j];
            }
            cout << ' ';

            for(int j=0; j<N; j++){
                cout << board[j][N-1-i];
            }
            cout << " \n";
        }
    }
}

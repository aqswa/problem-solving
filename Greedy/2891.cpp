//
// Created by LG on 2023-03-01.
//
#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, s, r;
    cin >> n >> s >> r;

    vector<int> teams(n, 0);

    for(int i=0; i<s; i++){
        int a;
        cin >> a;
        teams[a-1]--;
    }

    for(int i=0; i<r; i++){
        int a;
        cin >> a;
        teams[a-1]++;
    }

    for(int i=0; i<n; i++){
        if(teams[i] == -1){
            if(i == 0) {
                if(teams[i+1] == 1) { //음수여도 true 처리되므로 == 1 이라고 명시해줘야 한다.
                    teams[i]++;
                    teams[i + 1]--;
                }
            }
            else if(i == n-1){
                if(teams[i-1] == 1)
                    teams[i]++;
            }
            else {
                if(teams[i-1] == 1)
                    teams[i]++;
                else if(teams[i+1] == 1){
                    teams[i]++;
                    teams[i+1]--;
                }
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(teams[i] == -1)
            cnt++;
    }
    cout << cnt;
}

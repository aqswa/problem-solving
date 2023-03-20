//
// Created by LG on 2023-03-20.
//
#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int n;
vector<bool> row;
vector<bool> col;
vector<vector<bool>> diagonal;

void backtrack(int r, int c, int cnt){
    if(cnt == n){
        ans++;
        return;
    }

    for(int i=r; i<=n; i++){
        for(int j=c; j<=n; j++){
            if(row[i] || col[j])
                continue;
            row[i] = true;
            col[j] = true;

            if(j==n)
                backtrack(i+1, 1, cnt+1);
            else
                backtrack(i, j+1, cnt+1);
            row[i] = false;
            col[j] = false;

        }
    }
}

int main(){
    cin >> n;
    row.assign(n+1, false);
    col.assign(n+1, false);
    diagonal.assign(n+1, vector<bool>(n+1, false));

    backtrack(1, 1, 0);

    cout << ans;

}

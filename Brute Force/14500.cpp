//
// Created by LG on 2023-03-19.
//
#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int m, vector<vector<int>> paper){
    int max = 0;
    for(int i=0; i<n; i++){ //테트로미노 1
        for(int j=0; j<m-3; j++){
            int sum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i][j+3];
            if(sum > max)
                max = sum;
        }
    }

    for(int i=0; i<n-1; i++) { //테트로미노 3, 5
        for (int j = 0; j < m - 2; j++) {
            int sum = paper[i][j] + paper[i][j + 1] + paper[i][j + 2];
            if (sum + paper[i + 1][j] > max)
                max = sum + paper[i + 1][j];
            if (sum + paper[i + 1][j + 1] > max)
                max = sum + paper[i + 1][j + 1];
            if (sum + paper[i + 1][j + 2] > max)
                max = sum + paper[i + 1][j + 2];
        }
    }

    for(int i=1; i<n; i++) { //테트로미노 3, 5
        for (int j = 0; j < m - 2; j++) {
            int sum = paper[i][j] + paper[i][j + 1] + paper[i][j + 2];
            if (sum + paper[i - 1][j] > max)
                max = sum + paper[i - 1][j];
            if (sum + paper[i - 1][j + 1] > max)
                max = sum + paper[i - 1][j + 1];
            if (sum + paper[i - 1][j + 2] > max)
                max = sum + paper[i - 1][j + 2];
        }
    }

    for(int i=0; i<n-1; i++){ //테트로미노 2, 4
        for(int j=0; j<m-1; j++) {
            int sum = paper[i][j] + paper[i][j + 1];
            if (sum + paper[i + 1][j] + paper[i + 1][j + 1] > max)
                max = sum + paper[i + 1][j] + paper[i + 1][j + 1];
            if (j != 0) {
                if (sum + paper[i + 1][j - 1] + paper[i + 1][j] > max)
                    max = sum + paper[i + 1][j - 1] + paper[i + 1][j];
            }
            if (j != m - 2) {
                if (sum + paper[i + 1][j+1] + paper[i + 1][j + 2] > max)
                    max = sum + paper[i + 1][j+1] + paper[i + 1][j + 2];
            }
        }
    }

    return max;
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> paper1(n, vector<int>(m, 0));
    vector<vector<int>> paper2(m, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> paper1[i][j];
            paper2[j][i] = paper1[i][j];
        }
    }

    int a = solve(n, m, paper1);
    int b = solve(m, n, paper2);

    cout << (a > b ? a : b);
}

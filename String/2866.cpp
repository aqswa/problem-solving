//
// Created by LG on 2022-03-05.
//
#include <iostream>
#include <vector>

using namespace std;

int min_r;
vector<vector<char>> alphabet;

void findDiff(int a, int b, int r){

    while(true){
        r--;
        if(alphabet[r][a] != alphabet[r][b])
            break;
    }

    if(min_r > r)
        min_r = r;
}

int main(){

    int r, c;
    cin >> r >> c;

    alphabet.assign(r, vector<char>(c, ' '));
    min_r = r-1;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> alphabet[i][j];
        }
    }

    for(int i=0; i<c-1; i++){
        for(int j=i+1; j<c; j++){
            if(alphabet[r-1][i] == alphabet[r-1][j])
                findDiff(i, j, r-1);
        }
    }

    cout << min_r;

    return 0;
}

//
// Created by LG on 2022-04-02.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> levels(n);
    vector<int> maxi(n);
    for(int i=0; i<n; i++)
        cin >> levels[i] >> maxi[i];

    while(m--){
        int cp;
        cin >> cp;
        cout << levels[lower_bound(maxi.begin(), maxi.end(), cp) - maxi.begin()] << '\n';
    }
}

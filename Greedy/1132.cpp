//
// Created by LG on 2022-04-11.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<long long, int>> weight(10, {0, 0});
    for(int i=0; i<10; i++)
        weight[i].second = i;
    vector<bool> no_zero(10, false);
    while (n--) {
        string s;
        cin >> s;
        no_zero[s[0] - 'A'] = true;
        for (int i = 0; i < s.length(); i++)
            weight[s[s.length() - 1 - i] - 'A'].first += (long long)pow(10, i);
    }

    sort(weight.begin(), weight.end());
    int zero = 0;
    for (int i = 0; i < 10; i++){
        if (!no_zero[weight[i].second]) {
            zero = i;
            break;
        }
    }

    long long ans = 0;
    bool flag = false;
    for(int i=0; i<weight.size(); i++){
        if(i == zero) {
            flag = true;
            continue;
        }
        if(flag)
            ans += weight[i].first * (i);
        else
            ans += weight[i].first * (i + 1);
    }
    cout << ans;
}

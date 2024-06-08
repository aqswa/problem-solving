//
// Created by LG on 2024-06-08.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<int> height(W, 0);
    for(int i=0; i<W; i++) {
        cin >> height[i];
    }

    int water = 0;
    for(int i=1; i<W-1; i++) {
        int left = 0, right = 0;
        for(int j=i-1; j>=0; j--) {
            if(height[j] > left) {
                left = height[j];
            }
        }

        for(int j=i+1; j<W; j++) {
            if(height[j] > right) {
                right = height[j];
            }
        }

        int top = left > right ? right : left;
        if(top > height[i]) {
            water += top - height[i];
        }
    }

    cout << water;
}

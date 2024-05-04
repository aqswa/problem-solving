#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> nums;

int main() {
    cin >> N;
    nums.assign(N, 0);

    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int cnt = 0;
    for(int i=0; i<N; i++) {
        int s = 0;
        int e = N-1;
        while(s < e) {
            if(s == i) {
                s++;
                continue;
            }
            if(e == i) {
                e--;
                continue;
            }

            if(nums[s] + nums[e] < nums[i]) {
                s++;
            } else if(nums[s] + nums[e] > nums[i]) {
                e--;
            } else {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;

int main() {
    cin >> N >> M;

    nums.assign(N, 0);

    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int en = 0;
    int answer = nums[N-1] - nums[0];
    for(int i=0; i<N; i++) {
        while(en < N && nums[en] - nums[i] < M) en++;
        if(en == N) break;
        answer = min(nums[en] - nums[i], answer);
    }

    cout << answer;

}

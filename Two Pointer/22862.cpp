#include <iostream>
#include <vector>

using namespace std;

int S, N;
vector<int> nums;

int main() {
    cin >> S >> N;
    nums.assign(S, 0);

    for(int i=0; i<S; i++) {
        cin >> nums[i];
    }

    int cnt, answer;
    if(nums[0] % 2 == 0) {
        cnt = 0;
        answer = 1;
    } else {
        cnt = 1;
        answer = 0;
    }

    int s = 0, e = 0;
    while(e < S-1 && s < S) {
        if(nums[e+1] % 2 == 0) {
            e++;
            answer = max(answer, e - s + 1 - cnt);
        } else {
            if(cnt + 1 > N) {
                while(s < S) {
                    if(nums[s++] % 2 != 0) {
                        break;
                    }
                }
            } else {
                cnt++;
            }
            e++;
        }
    }

    cout << answer;
}
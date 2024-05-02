#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> coding;
int large = 0;
int small = 0;

void find_large(int num, int start, int end) {
    if(start > end) {
        return;
    }

    int mid = (start + end) / 2;

    if(coding[mid] <= num) {
        find_large(num, mid+1, end);
    } else {
        large = min(large, mid);
        find_large(num, start, mid-1);
    }
}

void find_small(int num, int start, int end) {
    if(start > end) {
        return;
    }

    int mid = (start + end) / 2;

    if(coding[mid] >= num) {
        find_small(num, start, mid-1);
    } else {
        small = max(small, mid);
        find_small(num, mid+1, end);
    }
}

int main()
{
    cin >> N;
    coding.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> coding[i];
    }

    sort(coding.begin(), coding.end());

    long long total = 0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            int num = - (coding[i] + coding[j]);
            large = N; //num보다 큰 값 중 가장 작은 idx
            small = j; //num보다 작은 값 중 가장 큰 idx
            find_large(num, j+1, N-1);
            find_small(num, j+1, N-1);
            total += (large - small - 1);
        }
    }

    cout << total;
}

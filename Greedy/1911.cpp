//
// Created by LG on 2023-02-23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> well(n, {0, 0});

    for(int i=0; i<n; i++){
        cin >> well[i].first >> well[i].second;
    }

    sort(well.begin(), well.end());
    //sort(v.begin(), v.end()); // 오름차순
    //sort(v.begin(), v.end(), less<>()); // 오름차순
    //sort(v.begin(), v.end(), greater<>()); // 내림차순
    //sort(v.begin(), v.end(), compare); //compare의 리턴 값이 false면 swap, priority_queue의 비교연산자와 swap 조건이 반대

    int cur = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(cur >= well[i].second)
            continue; //아래 if문 건너뛰고 다음 웅덩이로.
        if(cur > well[i].first){
            int len = well[i].second - cur;
            if(len%l == 0){
                cnt += len/l;
                cur = well[i].second;
            }
            else{
                cnt += len/l + 1;
                cur = well[i].second + (l-len%l);
            }
        }
        else{
            int len = well[i].second - well[i].first;
            if(len%l == 0){
                cnt += len/l;
                cur = well[i].second;
            }
            else{
                cnt += len/l + 1;
                cur = well[i].second + (l-len%l);
            }
        }
    }

    cout << cnt;

    /*
     *  for(i=0;i<n;i++){
		    if(cur < well[i].first)
		        cur = well[i].first;
            b = ceil((double)(well[i].second - cur) / l);   복잡하게 나머지를 구하지 않고 ceil을 쓴다.
            cnt += b;
            cur += b * l;
        }
     */
}

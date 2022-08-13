#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//정렬과 약간의 그리디?

int addCount(vector<int> arr, int idx, int n){

    if(arr[idx+1] - arr[idx] > 4)
        return 4;

    int cnt = 1;
    int add_cnt = 0;
    while(true){
        if(idx == n-1){ //배열의 마지막 수라면
            add_cnt += (5-cnt); //더 필요한 만큼 연속한 수를 추가하고 반복문 종료
            break;
        }
        int gap = arr[idx+1] - arr[idx]; // 현재 수와 다음 수의 간격
        cnt += (gap); //다음 수와의 간격이 2였다면 그 간격을 채운 후엔 연속한 숫자가 2개 증가함
        add_cnt += (gap -1); //간격 -1 만큼 숫자를 추가함.
        idx++;
        if(cnt >= 5)
            break; //연속한 수가 5개라면 반복문 종료함
    }

    return add_cnt;
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int min_add = 4;
    for(int i=0; i<n-1; i++){
        min_add = min(min_add, addCount(arr, i, n));
    }

    cout << min_add;

}
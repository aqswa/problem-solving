//
// Created by LG on 2023-02-22.
//
#include <iostream>

using namespace  std;

int main(){
    long long x, y, w, s; //int로 선언 시 오버플로우

    cin >> x >> y >> w >> s;

    if(x < y){
        swap(x, y);
    }

    long long ans = 0;
    if(s < w*2)
        ans += s*y;
    else
        ans += 2*w*y;

    if(s < w)
        ans += 2*s*((x-y)/2) + w*((x-y)%2);
    else
        ans += w*(x-y);

    cout << ans;
}

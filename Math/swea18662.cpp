//
// Created by LG on 2023-11-17.
//
#include <iostream>

using namespace std;

double abs(double a, double b){
    return a - b >= 0 ? a - b : b - a;
}

int main(){
    int t;
    cin >> t;

    for(int i=1; i<=t; i++){
        cout << "#" << i << ' ';
        double a, b, c;
        cin >> a >> b >> c;

        double ans = 1000.0;
        if(c - b == b - a)
            ans = 0.0;

        double na = 2 * b - c;
        if(abs(na, a) < ans)
            ans = abs(na, a);

        double nb = (a + c) / 2.0; //division operator는 분모의 자료형을 따라간다
        if(abs(nb, b) < ans)
            ans = abs(nb, b);

        double nc = 2 * b - a;
        if(abs(nc, c) < ans)
            ans = abs(nc, c);

        cout << fixed; //소숫점 아래 숫자의 출력 범위만 설정
        cout.precision(1);
        cout << ans << '\n';
    }
}

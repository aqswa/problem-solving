//
// Created by LG on 2023-01-20.
//
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int n_five = 0, m_five = 0;
    int n_two = 0, m_two = 0;
    int r_five = 0, r_two = 0;

    long long pow_five = 5;
    long long pow_two = 2;
    while (pow_five <= n || pow_two <= n) {
        n_five += n / pow_five;   // n!에서 5는 5, 10, 15, 20, 25, 30, ... 5 간격이므로 5의 배수는 n//5개 있고,
        n_two += n / pow_two;     // 마찬가지로 25의 배수도 n//25개 있음. 25의 배수는 5의 배수에 포함됨. n//5 + n//25 + n//125 ... 가 n!의 5의 지수

        m_five += m / pow_five;   // nCr = n!/r!(n-r)! 이므로 n!, r!, (n-r)!에서 각각 2와 5의 지수를 구하고 n!의 지수에서 r!, (n-r)!의 지수를 뺀다.
        m_two += m / pow_two;     // 뺀 결과 2의 지수와 5의 지수가 모두 1 이상이라면 둘 중 더 작은 수를 출력, 둘 중 하나라도 0이라면 10의 배수는 없으므로 끝자리 0의 개수는 0개.

        r_five += (n-m) / pow_five;
        r_two += (n-m) / pow_two;

        pow_five *= 5;
        pow_two *= 2;
    }

    n_five = n_five - m_five - r_five;
    n_two = n_two - m_two - r_two;

    if (n_five > 0 && n_two > 0) {
        cout << ((n_five > n_two) ? n_two : n_five);
    } else
        cout << 0;

    return 0;
}

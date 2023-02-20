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
        n_five += n / pow_five;
        m_five += m / pow_five;

        n_two += n / pow_two;
        m_two += m / pow_two;

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

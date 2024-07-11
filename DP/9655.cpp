//
// Created by LG on 2024-07-11.
//
#include <iostream>

using namespace std;

int main() {
    int rock;
    cin >> rock;

    int share = rock / 3;
    int remainder = rock % 3;

    if(remainder ==  0) {
        if(share % 2 == 0) {
            cout << "CY";
        } else {
            cout << "SK";
        }
    } else if(remainder == 1) {
        if(share % 2 == 0) {
            cout << "SK";
        } else {
            cout << "CY";
        }
    } else {
        if(share % 2 == 0) {
            cout << "CY";
        } else {
            cout << "SK";
        }
    }
}

//
// Created by LG on 2023-01-15.
//
#include <iostream>

using namespace std;

int euclidean(int a, int b){
    if(b==0)
        return a;
    return euclidean(b, a%b);
}

int main(){
    int n;
    cin >> n;
    int radius[n];

    for(int i=0; i<n; i++)
        cin >> radius[i];

    for(int i=1; i<n; i++){
        int a = euclidean(radius[0], radius[i]);
        cout << radius[0]/a << '/' << radius[i]/a << '\n';
    }
}

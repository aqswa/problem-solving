//
// Created by LG on 2023-02-21.
//
#include <iostream>
#include <cmath> //math.h는 deprecated, cmath 사용

using namespace std;

double get_distance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)); //sqrt는 double 반환
}

int main(){
    int t=0;
    cin >> t;

    pair<int, int> start;
    pair<int, int> end;

    while(t--){
        cin >> start.first >> start.second >> end.first >> end.second;
        int n=0, cnt=0;
        cin >> n;
        while(n--){
            int x, y, r;
            cin >> x >> y >> r;
            if(double(r) > get_distance(start.first, start.second, x, y)){
                if(double(r) < get_distance(end.first, end.second, x, y))
                    cnt++;
            }
            else if(double(r) > get_distance(end.first, end.second, x, y)){
                if(double(r) < get_distance(start.first, start.second, x, y))
                    cnt++;
            }
        }

        cout << cnt << '\n';
    }
}
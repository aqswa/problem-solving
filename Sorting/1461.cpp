//
// Created by LG on 2022-03-22.
//
//도서관
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, m, distance = 0;
    cin >> n >> m;

    //음수와 양수로 나눠서 벡터에 저장함
    vector<int> book_minus(0);
    vector<int> book_plus(0);
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        if(t < 0)
            book_minus.push_back(-t);
        else
            book_plus.push_back(t);
    }

    sort(book_minus.begin(), book_minus.end());
    sort(book_plus.begin(), book_plus.end());

    //두 배열의 인덱스를 저장할 변수 선언
    int index_minus = book_minus.size()-1;
    int index_plus = book_plus.size()-1;

    //양수 위치만 있을 때와, 음수 위치만 있을 때와 둘 다 있을 때로 나눔.
    if(index_plus < 0){
        distance += book_minus[index_minus];
        index_minus -= m;
    }
    else if(index_minus < 0){
        distance += book_plus[index_plus];
        index_plus -= m;
    }
    else{
        if(book_minus[index_minus] > book_plus[index_plus]){
            distance += book_minus[index_minus];
            index_minus -= m;
        }
        else{
            distance += book_plus[index_plus];
            index_plus -= m;
        }
    }

    while(true){
        if(index_plus < 0)
            break;
        distance += book_plus[index_plus]*2;
        index_plus -= m;
    }
    while(true){
        if(index_minus < 0)
            break;
        distance += book_minus[index_minus]*2;
        index_minus -= m;
    }

    cout << distance;
}

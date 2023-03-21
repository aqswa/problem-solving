//
// Created by LG on 2023-03-21.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    priority_queue<int> pq;
    while(n--){
        int a;
        cin >> a;
        if(a == 0){
            if(pq.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            for(int i=0; i<a; i++){
                int b;
                cin >> b;
                pq.push(b);
            }
        }
    }
}

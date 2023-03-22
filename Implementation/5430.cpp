//
// Created by LG on 2023-03-09.
//
#include <iostream>
#include <vector>
#include <string> //stoi

using namespace std;

vector<int> input(int n, string str){

    vector<int> list;

    string s = "";
    for(int i=1; i<str.length()-1; i+=1){
        if(str[i] == ','){
            list.push_back(stoi(s));
            s = "";
            continue;
        }
        s += str[i];
    }

    if(s != "")
        list.push_back(stoi(s));

    return list;
}

void output(int front, int back, bool direction, vector<int> &list){
    cout << '[';

    if(direction){ //정방향이면
        for(int i=front; i<=back; i++){ //첫 번째부터 마지막까지 출력
            if(i==back){ //마지막 원소라면 comma 뺌
                cout << list[i];
            }
            else {
                cout << list[i] << ",";
            }
        }
        cout << "]" << '\n';
    }
    else{ //역방향이면
        for(int i=back; i>=front; i--){
            if(i==front){
                cout << list[i];
            }
            else {
                cout << list[i] << ",";
            }
        }
        cout << "]" << '\n';
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        string p, str;
        int n;
        cin >> p >> n >> str;

        vector<int> list;
        list = input(n, str);

        int front = 0, back = list.size()-1;
        bool direction = true; //true 정방향, false 역방향

        for(int i=0; i<p.length(); i++){
            if(p[i] == 'R'){
                direction = !direction;
            }
            else{
                if(front > back){
                    cout << "error" << '\n';
                    break;
                }
                if(direction){
                    front++;
                }
                else{
                    back--;
                }
            }
            if(i==p.length()-1){
                output(front, back, direction, list);
            }
        }
        //cout << "front" << front << ' ' << "back" << back << '\n';
    }

    return 0;
}

//
// Created by LG on 2023-04-17.
//
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int year = stoi(today.substr(0, 4));
    int month = (today[5]-'0')*10 + (today[6]-'0');
    int day = (today[8]-'0')*10 + (today[9]-'0');

    map<char, int> terms_map;
    for(auto t: terms){
        if(t.length() == 3){
            terms_map.insert({t[0], int(t[2]-'0')}); //map insert
        }
        else if(t.length() == 5){
            terms_map.insert({t[0], 100}); //map insert
        }
        else{
            int m = (t[2]-'0')*10 + (t[3]-'0');
            terms_map.insert({t[0], m}); //map insert
        }
    }

    for(int i=0; i<privacies.size(); i++){
        int y = stoi(privacies[i].substr(0, 4));
        int m = (privacies[i][5]-'0')*10 + (privacies[i][6]-'0');
        int d = (privacies[i][8]-'0')*10 + (privacies[i][9]-'0');
        char type = privacies[i][11];

        m += terms_map[type];
        if(m > 12){ //모듈러 연산. 달이 12의 배수인 경우를 생각해야함.
            if(m%12 == 0){
                y += m/12-1;
                m = 12;
            }
            else{
                y += m/12;
                m %= 12;
            }
        }


        if(d == 1){
            if(m == 1){ //1월 1일이면
                y -= 1;
                m = 12;
                d = 28;
            }
            else{ //2~12월 1일이면
                m -= 1;
                d = 28;
            }
        }
        else{
            d -= 1;
        }


        if(y < year){
            answer.push_back(i+1);
        }
        else if(y == year){
            if(m < month){
                answer.push_back(i+1);
            }
            else if(m == month){
                if(d < day){
                    answer.push_back(i+1);
                }
            }
        }
    }

    return answer;
}

//
// Created by LG on 2023-02-24.
//
#include <iostream>

using namespace  std;

int main() {
    string document, word;
    getline(cin, document); //줄바꿈 문자 제외하고 한 줄 입력받기
    getline(cin, word);

    int cnt = 0;
    while(true) {
        if (document.find(word) != string::npos) { //문자열.find() 에서 찾지 못하면 string::npos 반환
            int index = document.find(word);
            cnt++;
            if(document.length() >= word.length())
                document = document.substr(index + word.length(), document.length() - word.length()); //substr(문자열 시작 인덱스, 문자열 길이)
        }
        else
            break;
    }

    cout << cnt;
}

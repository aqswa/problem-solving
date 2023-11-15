//
// Created by LG on 2023-11-15.
//
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int binary[100] = {0};

bool can_tree(int s, int e){
    if(s + 1 == e)
        return true;

    int mid = (s + e) / 2;
    if(binary[mid] == 0){
        for(int i=s; i<e; i++){ //자식 노드에 1이 있으면 안됨
            if(binary[i] == 1)
                return false;
        }
        return true;
    }

    if(can_tree(s, mid) && can_tree(mid+1, e))
        return true;
    else
        return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(int i=0; i<numbers.size(); i++){
        memset(binary, 0, sizeof(binary));
        int bin_length = 0;
        while(pow(2, bin_length) <= numbers[i]){
            bin_length++;
        }

        int full_length = 1;
        while(full_length <= bin_length){
            full_length *= 2;
        }
        full_length -= 1;

        for(int j=full_length-1; j>=0; j--){
            binary[j] = numbers[i] % 2;
            numbers[i] /= 2;
        }

        if(can_tree(0, full_length)){
            answer.emplace_back(1);
        }
        else{
            answer.emplace_back(0);
        }
    }

    return answer;
}

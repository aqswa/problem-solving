//
// Created by LG on 2023-10-19.
//
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genres_total;
    map<string, map<int, int>> plays_cnt;

    for(int i=0; i<genres.size(); i++){
        genres_total[genres[i]] += plays[i];
        plays_cnt[genres[i]].insert({i, plays[i]});
    }

    while(genres_total.size() > 0){
        string genre = "";
        int max = 0;
        for(auto iter=genres_total.begin(); iter != genres_total.end(); iter++){
            if(iter->second > max){
                max = iter->second;
                genre = iter->first;
            }
        }

        genres_total.erase(genre);

        for(int i=0; i<2; i++){
            int max = 0;
            int idx = -1;
            for(auto iter=plays_cnt[genre].begin(); iter!=plays_cnt[genre].end(); iter++){
                if(iter->second > max){
                    max = iter->second;
                    idx = iter->first;
                }
            }
            if(idx == -1)
                break;

            plays_cnt[genre].erase(idx);
            answer.push_back(idx);
        }
    }

    return answer;
}

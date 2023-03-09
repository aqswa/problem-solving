//
// Created by LG on 2023-03-08.
//
#include <iostream>
#include <vector>

using namespace std;

int distance(pair<int, int> &p1, pair<int, int> &p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void find_combination(int size, int choose, vector<vector<bool>> &close, vector<bool> list, int cur, int index) {
    if(cur == choose){
        close.push_back(list);
        return;
    }

    for(int i=index; i<size; i++){
        list[i] = true;
        find_combination(size, choose, close, list, cur+1, i+1);
        list[i] = false;
    }
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> city(n, vector<int>(n, 0));
    vector<pair<int, int>> house;
    vector<pair<int, int>> chicken;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> city[i][j];
            if(city[i][j] == 1){
                house.emplace_back(i, j);  //push_back({i, j})
            }
            else if(city[i][j] == 2){
                chicken.emplace_back(i, j);
            }
        }
    }

    int choose = chicken.size() - m;
    vector<vector<bool>> close_combination;
    vector<bool> list(chicken.size(), false); //false이면 제거되지 않은 치킨집
    find_combination(chicken.size(), choose, close_combination, list, 0, 0);

    int min_chicken_distance = 10001;
    for(int i=0; i<close_combination.size(); i++){
        int chicken_distance = 0;
        vector<bool> chickens = close_combination[i];
        for(int j=0; j<house.size(); j++){
            int closest = 101;
            for(int k=0; k<chicken.size(); k++) {
                if (!chickens[k]) {
                    int dist = distance(house[j], chicken[k]);
                    if (dist < closest)
                        closest = dist;
                }
            }
            chicken_distance += closest;
        }

        if(chicken_distance < min_chicken_distance){
            min_chicken_distance = chicken_distance;
        }
    }

    cout << min_chicken_distance;
}
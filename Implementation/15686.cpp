//
// Created by LG on 2023-03-08.
//
#include <iostream>
#include <vector>

using namespace std;

int distance(pair<int, int> &p1, pair<int, int> &p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
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

    int chicken_cnt = chicken.size();

    vector<bool> chicken_check(chicken_cnt, true); //사라진 치킨집이면 false
    while(chicken_cnt > m){
        int min_chicken_distance = 10000;
        int next_chicken_index = 0;
        for(int i=0; i<chicken.size(); i++){ //i번 치킨집을 제거했을 때
            if(!chicken_check[i]) //이미 제거된 치킨집이면 넘어감.
                continue;
            int chicken_distance = 0; //도시의 치킨 거리
            for(int j=0; j<house.size(); j++){ //
                pair<int, int> h = house[j];
                int min = 101;
                for(int k=0; k<chicken.size(); k++) {
                    if(k==i || !chicken_check[k]) //i번 치킨집이거나 이미 없앤 치킨집이면 다음 치킨집과의 거리 잼
                        continue;
                    if (distance(h, chicken[k]) < min) { //지금 치킨집과의 거리가 가장 가까운 치킨집과의 거리보다 가깝다면
                        min = distance(h, chicken[k]);
                    }
                }
                chicken_distance += min;
            }

            if(chicken_distance < min_chicken_distance){
                min_chicken_distance = chicken_distance;
                next_chicken_index = i;
            }
        }
        chicken_check[next_chicken_index] = false;
        chicken_cnt--;
        cout << next_chicken_index << ' ';
    }

    int ans = 0;
    for(int i=0; i<house.size(); i++){
        int closest = 101;
        for(int j=0; j<chicken.size(); j++){
            if(chicken_check[j]){
                int dist = distance(house[i], chicken[j]);
                if(dist < closest)
                    closest = dist;
            }
        }
        ans += closest;
    }

    cout << ans;
}

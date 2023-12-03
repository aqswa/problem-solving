//
// Created by LG on 2023-11-20.
//
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> ci;

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    vector<vector<ci>> parent(51, vector<ci>(51));
    vector<vector<string>> value(51, vector<string>(51, "EMPTY"));
    for(int i=1; i<51; i++) {
        for(int j=1; j<51; j++) {
            parent[i][j] = {i, j};
        }
    }

    for(int i=0; i<commands.size(); i++){
        string s;
        vector<string> sep_command;
        stringstream ss(commands[i]);
        string token;
        while (ss >> token) sep_command.push_back(token);

        if(sep_command[0] == "UPDATE"){
            if(sep_command.size() == 4){ //update r1 c1 value
                int r = sep_command[1][0] - '0';
                int c = sep_command[2][0] - '0';
                ci p1 = parent[r][c];
                value[p1.first][p1.second] = sep_command[3];
            }
            else{ //update val1 val2
                string val1 = sep_command[1];
                string val2 = sep_command[2];
                for(int m=1; m<51; m++){
                    for(int n=1; n<51; n++){
                        if(value[m][n] == val1){
                            value[m][n] = val2;
                        }
                    }
                }
            }
        }
        else if(sep_command[0] == "MERGE"){ //merge r1 c1 r2 c2
            int r1 = sep_command[1][0] - '0';
            int c1 = sep_command[2][0] - '0';
            int r2 = sep_command[3][0] - '0';
            int c2 = sep_command[4][0] - '0';
            ci p1 = parent[r1][c1];
            ci p2 = parent[r2][c2];
            if(p1 != p2) {
                for(int m=1; m<51; m++){
                    for(int n=1; n<51; n++){
                        if(parent[m][n] == p2) {
                            parent[m][n] = p1;
                        }
                    }
                }
                if (value[p1.first][p1.second] == "EMPTY" && value[p2.first][p2.second] != "EMPTY") {
                    value[p1.first][p1.second] = value[p2.first][p2.second];
                } else {
                    value[p2.first][p2.second] = value[p1.first][p1.second];
                }
            }
        }
        else if(sep_command[0] == "UNMERGE"){ //unmerge r c
            int r = sep_command[1][0] - '0';
            int c = sep_command[2][0] - '0';
            ci p = parent[r][c];
            string val = value[p.first][p.second];
            for(int m=1; m<51; m++){
                for(int n=1; n<51; n++){
                    if(parent[m][n] == p){
                        parent[m][n] = {m, n};
                        value[m][n] = "EMPTY";
                    }
                }
            }
            value[r][c] = val;
        }
        else{
            int r = sep_command[1][0] - '0';
            int c = sep_command[2][0] - '0';
            answer.push_back(value[parent[r][c].first][parent[r][c].second]);
        }

        for(int m=1; m<5; m++){
            for(int n=1; n<5; n++){
                cout << value[m][n] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << ' ';
    }

    return answer;
}

int main(){
    vector<string> commands = {"MERGE 1 1 2 2", "MERGE 1 1 3 3", "UPDATE 3 3 A", "PRINT 1 1", "PRINT 2 2", "PRINT 3 3"};

    solution(commands);
}

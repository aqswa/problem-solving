//
// Created by LG on 2023-11-20.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int, int> ci;

struct Cell{
    string value;
    vector<ci> merged;
};

vector<vector<Cell>> cell(51, vector<Cell>(51, {"EMPTY", {}}));

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(int i=1; i<51; i++){
        for(int j=1; j<51; j++){
            cell[i][j].merged.emplace_back(i, j);
        }
    }

    for(int i=0; i<commands.size(); i++){
        string s;
        vector<string> sep_command;
        for(int j=0; j<commands[i].size(); j++){
            if(commands[i][j] == ' '){
                sep_command.push_back(s);
                s = "";
                continue;
            }
            s += commands[i][j];
        }
        sep_command.push_back(s);

        if(sep_command[0] == "UPDATE"){
            if(sep_command.size() == 4){
                int r = sep_command[1][0] - '0';
                int c = sep_command[2][0] - '0';
                cell[r][c].value = sep_command[3];
                vector<ci> merged_cells = cell[r][c].merged;
                for(int l=1; l<merged_cells.size(); l++){
                    int nr = merged_cells[l].first;
                    int nc = merged_cells[l].second;
                    cell[nr][nc].value = sep_command[3];
                }
            }
            else{
                string val1 = sep_command[1];
                string val2 = sep_command[2];
                for(int l=1; l<51; l++){
                    for(int m=1; m<51; m++){
                        if(cell[l][m].value == val1){
                            cell[l][m].value = val2;
                            vector<ci> merged_cells = cell[l][m].merged;
                            for(int n=1; n<merged_cells.size(); n++){ //병합된 셀 내용 변경
                                int nr = merged_cells[n].first;
                                int nc = merged_cells[n].second;
                                cell[nr][nc].value = val2;
                            }
                        }
                    }
                }
            }
        }
        else if(sep_command[0] == "MERGE"){
            int r1 = sep_command[1][0] - '0';
            int c1 = sep_command[2][0] - '0';
            int r2 = sep_command[3][0] - '0';
            int c2 = sep_command[4][0] - '0';

            vector<ci> merged1 = cell[r1][c1].merged;
            vector<ci> merged2 = cell[r2][c2].merged;
            for(int l=0; l < merged1.size(); l++){
                int nr = merged1[l].first;
                int nc = merged1[l].second;
                for(int m=0; m < merged2.size(); m++){
                    cell[nr][nc].merged.emplace_back(merged2[m].first, merged2[m].second);
                }
            }

            for(int l=0; l < merged2.size(); l++){
                int nr = merged2[l].first;
                int nc = merged2[l].second;
                cell[nr][nc].value = cell[r1][c1].value;
                for(int m=0; m < merged1.size(); m++){
                    cell[nr][nc].merged.emplace_back(merged1[m].first, merged1[m].second);
                }
            }
        }
        else if(sep_command[0] == "UNMERGE"){
            int r = sep_command[1][0] - '0';
            int c = sep_command[2][0] - '0';
            vector<ci> merged_cells = cell[r][c].merged;
            for(int l=1; l<merged_cells.size(); l++){ //병합되었던 셀들 초기화
                int nr = merged_cells[l].first;
                int nc = merged_cells[l].second;
                cell[nr][nc].merged = {{nr, nc}};
                cell[nr][nc].value = "EMPTY";
            }
            cell[r][c].merged = {{r, c}};
        }
        else{
            int r = sep_command[1][0] - '0';
            int c = sep_command[2][0] - '0';
            answer.push_back(cell[r][c].value);
        }

        for(int l=1; l<5; l++){
            for(int m=1; m<5; m++){
                cout << cell[l][m].value << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return answer;
}

int main(){
    vector<string> commands = {"UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1"};

    solution(commands);
}

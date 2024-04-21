#include <string.h>
#include <vector>

using namespace std;

int deltas[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int ans = 100;
int N, M;
vector<vector<bool>> blue_visited;
vector<vector<bool>> red_visited;
vector<vector<int>> Maze;
void backtracking(int cnt, int rr, int rc, int br, int bc) {
    if(Maze[rr][rc] == 3 && Maze[br][bc] == 4) { //둘 다 도착
        if(cnt < ans) {
            ans = cnt;
        }
        return;
    } else if(Maze[rr][rc] == 3) { //빨간 공만 도착한 경우
        for(int i=0; i<4; i++) {
            int nbr = br + deltas[i][0];
            int nbc = bc + deltas[i][1];
            if (nbr >= 0 && nbr < N && nbc >= 0 && nbc < M && !blue_visited[nbr][nbc] && Maze[nbr][nbc] != 5) {
                if (nbr == rr && nbc == rc) //빨간 공이 있는 위치라면
                    continue;

                blue_visited[nbr][nbc] = true;
                backtracking(cnt + 1, rr, rc, nbr, nbc);
                blue_visited[nbr][nbc] = false;
            }
        }
    } else if(Maze[br][bc] == 4) { //파란 공만 도착한 경우
        for(int i=0; i<4; i++) {
            int nrr = rr + deltas[i][0];
            int nrc = rc + deltas[i][1];
            if(nrr >= 0 && nrr < N && nrc >= 0 && nrc < M && !red_visited[nrr][nrc] && Maze[nrr][nrc] != 5) {
                if (nrr == br && nrc == bc) //파란 공이 있는 위치라면
                    continue;

                red_visited[nrr][nrc] = true;
                backtracking(cnt + 1, nrr, nrc, br, bc);
                red_visited[nrr][nrc] = false;
            }
        }
    } else {
        for(int i=0; i<4; i++) {
            int nrr = rr + deltas[i][0];
            int nrc = rc + deltas[i][1];
            if(nrr >= 0 && nrr < N && nrc >= 0 && nrc < M && !red_visited[nrr][nrc] && Maze[nrr][nrc] != 5) {
                for(int j=0; j<4; j++) {
                    int nbr = br + deltas[j][0];
                    int nbc = bc + deltas[j][1];
                    if(nbr >= 0 && nbr < N && nbc >= 0 && nbc < M && !blue_visited[nbr][nbc] && Maze[nbr][nbc] != 5) {
                        if(nbr == nrr && nbc == nrc) //같은 위치로 이동할 수 없음
                            continue;
                        if(nbr == rr && nbc == rc && nrr == br && nrc == bc) //서로의 위치로 이동할 수 없음
                            continue;

                        red_visited[nrr][nrc] = true;
                        blue_visited[nbr][nbc] = true;

                        backtracking(cnt+1, nrr, nrc, nbr, nbc);

                        red_visited[nrr][nrc] = false;
                        blue_visited[nbr][nbc] = false;
                    }
                }
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    int rr, rc, br, bc;
    N = maze.size();
    M = maze[0].size();

    Maze = maze;
    red_visited.assign(N, vector<bool>(M, false));
    blue_visited.assign(N, vector<bool>(M, false));

    for(int i=0; i<maze.size(); i++) {
        for(int j=0; j<maze[0].size(); j++) {
            if(maze[i][j] == 1) {
                rr = i;
                rc = j;
                red_visited[i][j] = true;
            } else if(maze[i][j] == 2) {
                br = i;
                bc = j;
                blue_visited[i][j] = true;
            }
        }
    }

    backtracking(0, rr, rc, br, bc);

    return ans == 100 ? 0 : ans;
}

int main() {

}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
 
public class Solution {
    static ArrayList<int []> cores;
    static int N;
    static int board[][];
    static int max_core, min_length;
    static int deltas[][] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
         
        int T = Integer.parseInt(br.readLine());
        for(int t=1; t<=T; t++) {
            N = Integer.parseInt(br.readLine());
            board = new int[N][N];
            cores = new ArrayList<>();
            max_core = 0;
            min_length = Integer.MAX_VALUE;
            for(int i=0; i<N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j=0; j<N; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                    if(board[i][j] == 1) {
                        cores.add(new int [] {i, j});
                    }
                }
            }
             
            dfs(0, 0, 0);
            sb.append("#" + t + " " + min_length + " " + "\n");
        }
        System.out.println(sb);
    }
     
    public static void dfs(int idx, int cnt, int length) {
        if(idx == cores.size()) {
            if(cnt > max_core) {
                max_core = cnt;
                min_length = length;
            }
            else if(cnt == max_core) {
                if(length < min_length) {
                    min_length = length;
                }
            }
            return;
        }
         
        int r = cores.get(idx)[0];
        int c = cores.get(idx)[1];
        if(r == 0 || r == N-1 || c == 0 || c == N-1) { //가장자리라서 이미 연결된 경우
            dfs(idx+1, cnt+1, length);
        }
        else {
            dfs(idx+1, cnt, length); //연결하지 않는 경우
            for(int i=0; i<4; i++) {
                if(check(r, c, i)) { //좌표, 확인할 방향
                    int len = connect(r, c, i);
                    dfs(idx+1, cnt+1, length + len);
                    disconnect(r, c, i);
                }
            }
        }
    }
     
    public static boolean check(int r, int c, int dir) {
        while(true) {
            r += deltas[dir][0];
            c += deltas[dir][1];
            if(r < 0 || r >= N || c < 0 || c >= N)
                break;
            if(board[r][c] == 1) {
                return false;
            }
        }
        return true;
    }
     
    public static int connect(int r, int c, int dir) {
        int cnt = 0;
        while(true) {
            r += deltas[dir][0];
            c += deltas[dir][1];
            if(r < 0 || r >= N || c < 0 || c >= N)
                break;
            board[r][c] = 1;
            cnt++;
        }
        return cnt;
    }
     
    public static void disconnect(int r, int c, int dir) {
        while(true) {
            r += deltas[dir][0];
            c += deltas[dir][1];
            if(r < 0 || r >= N || c < 0 || c >= N)
                break;
            board[r][c] = 0;
        }
    }
}

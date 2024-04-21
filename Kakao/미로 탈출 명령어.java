import java.util.*;
import java.io.*;

class Solution {
    static int deltas[][] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    static char dir[] = {'d', 'l', 'r', 'u'};
    static char[] choosed;
    static int N, M, R, C, K;
    static String answer = null;
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = n; M = m; R = r; C = c; K = k;
        
        choosed = new char[k];
        dfs(x, y, 0, choosed);
        
        if(answer != null) {
            return answer;
        } else {
            return "impossible";
        }
    }
    
    public static void dfs(int r, int c, int cnt, char [] choosed) {
        if(answer != null) return;
        if(cnt == K && r == R && c == C) {
            answer = new String(choosed);
            return;
        }
        int shortest = Math.abs(R - r) + Math.abs(C - c);
        if((K - cnt) < shortest) return;
        if((K - cnt - shortest) % 2 != 0) return;
        
        for(int i=0; i<4; i++) {
            int nr = r + deltas[i][0];
            int nc = c + deltas[i][1];
            
            if(nr > 0 && nr <= N && nc > 0 && nc <= M) {
                choosed[cnt] = dir[i];
                dfs(nr, nc, cnt+1, choosed);
            }
        }
    }
}

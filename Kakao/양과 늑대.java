import java.util.*;
import java.io.*;

class Solution {
    static int [] INFO;
    static int [][] EDGES;
    static int N; //노드 개수
    static int [][] graph;
    static int answer = 0;
    public int solution(int[] info, int[][] edges) {
        INFO = info;
        EDGES = edges;
        N = info.length;
        
        boolean visited[] = new boolean[N];
        dfs(0, 0, 0, visited);
        return answer;
    }
    
    public static void dfs(int node, int sheep, int wolf, boolean [] visited) {
        visited[node] = true;
        if(INFO[node] == 0) {
            sheep++;
            if(sheep > answer) {
                answer = sheep;
            }
        } else {
            wolf++;
            if(wolf >= sheep) {
                return;
            }
        }
        
        for(int[] e : EDGES) {
            if(visited[e[0]] && !visited[e[1]]) {
                dfs(e[1], sheep, wolf, visited);
                visited[e[1]] = false;
            }
        }
    }
}

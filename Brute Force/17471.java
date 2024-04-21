package d0222;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj17471 {
	static int N;
	static int [] popul;
	static int [] parent;
	static boolean [][] graph;
	static int ans = Integer.MAX_VALUE;
	
	public static int checkPossible(ArrayList<Integer> g1, ArrayList<Integer> g2) {
		boolean visited[] = new boolean[N+1];		
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(g1.get(0));
		int cnt = 1;
		int total1 = popul[g1.get(0)];
		visited[g1.get(0)] = true;
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int node : g1) {
				if(!visited[node] && graph[cur][node] == true) {
					visited[node] = true;
					total1 += popul[node];
					q.add(node);
					cnt++;
				}
			}
		}
		
		if(cnt < g1.size()) {
			return -1;
		}
		
		q.add(g2.get(0));
		cnt = 1;
		int total2 = popul[g2.get(0)];
		visited[g2.get(0)] = true;
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int node : g2) {
				if(!visited[node] && graph[cur][node] == true) { //그룹 내 방문하지 않은 선거구 중 연결되어 있는 선거구라면
					visited[node] = true;
					total2 += popul[node];
					q.add(node);
					cnt++;
				}
			}
		}
		
		if(cnt < g2.size()) {
			return -1;
		}
		
		return Math.abs(total2 - total1);
	}
	
	public static void dfs(int idx, int cnt, int n, boolean visited[]) {
		if(cnt == n) {
			ArrayList<Integer> g1 = new ArrayList<Integer>();
			ArrayList<Integer> g2 = new ArrayList<Integer>();
			for(int i=1; i<=N; i++) {
				if(visited[i]) {
					g1.add(i);
				}
				else {
					g2.add(i);
				}
			}
			int diff = checkPossible(g1, g2);
			if(diff >= 0) {
				ans = Math.min(diff, ans);
			}
			return;
		}
		
		for(int i=idx; i<=N; i++) {
			visited[i] = true;
			dfs(i+1, cnt+1, n, visited);
			visited[i] = false;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(br.readLine());
		
		//make-set
		parent = new int[N+1];
		Arrays.fill(parent, -1);
		
		//인접행렬 그래프 초기화
		graph = new boolean[N+1][N+1];
		
		//선거구 별 인구 수 입력
		popul = new int[N+1];	
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=1; i<=N; i++) {
			popul[i] = Integer.parseInt(st.nextToken());
		}
		
		//연결된 선거구 입력
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(br.readLine());
			int cnt = Integer.parseInt(st.nextToken());
			for(int j=0; j<cnt; j++) {
				int v = Integer.parseInt(st.nextToken());
				graph[i][v] = true;
				graph[v][i] = true;
			}
		}
	
		//선거구에서 1 ~ N/2개 선거구 선택하는 경우 dfs
		for(int i=1; i<=N/2; i++) {
			dfs(1, 0, i, new boolean [N+1]);
		}
		
		if(ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		}
		else {
			System.out.println(ans);
		}
	}
}

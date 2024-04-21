import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj13023 {
	
	static int N, M;
	static ArrayList<ArrayList<Integer>> graph;
	static boolean flag;
	
	public static void dfs(int node, int cnt, boolean visited[]) {
		if(cnt == 5) {
			flag = true;
			return;
		}
		
		visited[node] = true;
		for(int next: graph.get(node)) {
			if(!visited[next]) {
				visited[next] = true;
				dfs(next, cnt+1, visited);
				visited[next] = false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		graph = new ArrayList<ArrayList<Integer>>();
		for(int i=0; i<N; i++) {
			graph.add(new ArrayList<Integer>());
		}
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			graph.get(u).add(v);
			graph.get(v).add(u);
		}
		
		for(int i=0; i<N; i++) {
			dfs(i, 1, new boolean [N]);
			if(flag)
				break;
		}
		
		System.out.println(flag ? 1 : 0);
	}
}

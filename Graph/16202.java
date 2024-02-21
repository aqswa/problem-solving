import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj16202 {
	
	static int N, M, K;
	static int parent [];
	static int edges[][];
	static boolean visited[];
	static boolean excluded[];
	static boolean flag;
	static int total;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); //정점 수
		M = Integer.parseInt(st.nextToken()); //간선 수
		K = Integer.parseInt(st.nextToken());
		
		parent = new int [N+1];
		edges = new int[M+1][2];
		excluded = new boolean[M+1];
		for(int i=1; i<=M; i++) {
			st = new StringTokenizer(br.readLine());
			edges[i][0] = Integer.parseInt(st.nextToken());
			edges[i][1] = Integer.parseInt(st.nextToken()); 
		}
		
		kruskal();
		while(K-- != 0) {
			if(!flag) {
				sb.append(total).append(" ");
				kruskal();
			}
			else {
				sb.append(0).append(" ");
			}
		}
		
		System.out.println(sb);
	}
	

	public static void kruskal() {
		boolean visited[] = new boolean[M+1];
		int edgeCnt = 0;
		total = 0;
		Arrays.fill(parent, -1);
		for(int i=1; i<=M; i++) {
			if(!excluded[i] && (find(edges[i][0]) != find(edges[i][1])) ) {
				union(edges[i][0], edges[i][1]);
				visited[i] = true;
				edgeCnt++;
				total += i;
			}
		}
		
		if(edgeCnt < N-1) {
			flag = true;
		}
		else {
			for(int i=1; i<=M; i++) {
				if(visited[i]) {
					excluded[i] = true;
					break;
				}
			}
		}
	}
	
	public static void union(int x, int y) {
		int p1 = find(x);
		int p2 = find(y);
		
		if(p1 < p2) {
			parent[p1] += parent[p2];
			parent[p2] = p1;
		}
		else {
			parent[p2] += parent[p1];
			parent[p1] = p2;
		}
	}
	
	public static int find(int x) {
		if(parent[x] < 0) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}
	
}

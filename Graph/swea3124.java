package d0222;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea3124 {
	static int V, E;
	static int edges[][];
	static int parent [];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			V = Integer.parseInt(st.nextToken()); //정점 개수
			E = Integer.parseInt(st.nextToken()); //간선 개수
			
			parent = new int[V+1];
			Arrays.fill(parent, -1);
			long total = 0;
			edges = new int[E][3];
			for(int i=0; i<E; i++) {
				st = new StringTokenizer(br.readLine());
				edges[i][0] = Integer.parseInt(st.nextToken());
				edges[i][1] = Integer.parseInt(st.nextToken());
				edges[i][2] = Integer.parseInt(st.nextToken());
			}
			
			Arrays.sort(edges, (o1, o2) -> {
				return Integer.compare(o1[2], o2[2]);
			});
			
			for(int i=0; i<E; i++) {
				if(find(edges[i][0]) != find(edges[i][1])) {
					union(edges[i][0], edges[i][1]);
					total += edges[i][2];
				}
			}
			
			sb.append("#").append(t).append(" ").append(total).append("\n");
		}
		
		System.out.println(sb);
		
	}
	
	public static int find(int x) {
		if(parent[x] < 0) {
			return x;
		}
		return parent[x] = find(parent[x]);
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
}

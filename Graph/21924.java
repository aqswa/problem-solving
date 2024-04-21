package d0221;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj21924 {
	static int N, M;
	static int edges[][];
	static int parent[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		long total = 0;
		parent = new int[N+1];
		Arrays.fill(parent, -1);
		edges = new int[M][3];
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			
			edges[i][0] = Integer.parseInt(st.nextToken());
			edges[i][1] = Integer.parseInt(st.nextToken());
			edges[i][2] = Integer.parseInt(st.nextToken());
			total += edges[i][2];
		}
		
		Arrays.sort(edges, (o1, o2) -> {
			return Integer.compare(o1[2], o2[2]);
		});
		
		long ans = kruskal();
		if(ans == -1) {
			System.out.println(-1);
		}
		else {
			System.out.println(total - ans);			
		}
	}

	public static long kruskal() {
		long weightSum = 0;
		int edgeCnt = 0;
		for(int i=0; i<M; i++) { //간선 개수만큼
			if(find(edges[i][0]) != find(edges[i][1])) {
				union(edges[i][0], edges[i][1]);
				weightSum += edges[i][2];
				if(++edgeCnt == N-1) {
					return weightSum;
				}
			}
		}
		
		return -1;
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

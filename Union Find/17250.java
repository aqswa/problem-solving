package algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj17250 {
	static int N, M;
	static int parent[];
	static int count[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken()); //은하의 수
		M = Integer.parseInt(st.nextToken()); //철도의 수
		
		parent = new int[N+1];
		count = new int[N+1];
		
		Arrays.fill(parent, -1);
		
		for(int i=1; i<=N; i++) {
			count[i] = Integer.parseInt(br.readLine());
		}
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			if(find(a) != find(b)) {
				union(a, b);
			}
			sb.append(count[find(a)] + "\n");			
		}
		
		System.out.println(sb);
	}
	
	public static void union(int a, int b) {
		int p1 = find(a);
		int p2 = find(b);
		
		if(p1 < p2) {
			parent[p1] += parent[p2];
			parent[p2] = p1;
			count[p1] += count[p2];
		}
		else {
			parent[p2] += parent[p1];
			parent[p1] = p2;
			count[p2] += count[p1];
		}
	}
	
	public static int find(int a) {
		if(parent[a] < 0) {
			return a;
		}
		return parent[a] = find(parent[a]);
	}
}

package d0221;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea3289 {
	static int N, M;
	static int parent [];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			sb.append("#").append(t).append(" ");
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			parent = new int [N+1];
			Arrays.fill(parent, -1);
			
			for(int i=0; i<M; i++) {	
				st = new StringTokenizer(br.readLine());
				int op = Integer.parseInt(st.nextToken());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				
				if(op == 0) {
					union(a, b);
				}
				else {
					if(find(a) == find(b)){
						sb.append(1);
					}
					else {
						sb.append(0);
					}
				}
			}
			sb.append("\n");
		}
		
		System.out.println(sb);
	}
	
	public static void union(int x, int y) {
		int p1 = find(x);
		int p2 = find(y);
		
		if(p1 == p2) {
			return;
		}
		
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

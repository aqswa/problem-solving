package d0222;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class swea1238 {
	static class Node {
		final int idx;
		final Node neigh;
		
		public Node(int idx, Node neigh) {
			this.idx = idx;
			this.neigh = neigh;
		}
	}
	
	public static Node[] graph;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		for(int t=1; t<=10; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int dSize = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			
			graph = new Node[101];
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<dSize/2; i++) {
				int src = Integer.parseInt(st.nextToken());
				int dest = Integer.parseInt(st.nextToken());
				graph[src] = new Node(dest, graph[src]);
				//graph[dest] = new Node(src, graph[dest]); // 양방향 간선인 경우
			}
		
			sb.append("#").append(t).append(" ").append(bfs(s)).append("\n");
		}
		
		System.out.println(sb);
		
	}
	
	public static int bfs(int s) {
		int max = 0;
		int idx = 0;
		
		boolean visited[] = new boolean[101];
		Queue<int []> q = new ArrayDeque<>();
		q.add(new int[] {s, 0});
		visited[s] = true;
		
		while(!q.isEmpty()) {
			int cur = q.peek()[0];
			int cnt = q.peek()[1];
			q.poll();
			
			for(Node next = graph[cur]; next != null; next = next.neigh) {
				if(!visited[next.idx]) {
					q.add(new int[] {next.idx, cnt+1});
					visited[next.idx] = true;
					if(cnt+1 > max) {
						max = cnt+1;
						idx = next.idx;
					}
					else if(cnt+1 == max) {
						if(next.idx > idx) {
							idx = next.idx;
						}
					}
					
				}
			}
		}
		
		return idx;
		
	}
}

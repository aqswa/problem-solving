import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj1504 {

	static int N, E;
	static int v1, v2;
	static int [] distance;
	static ArrayList<ArrayList<int[]>> graph;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList<ArrayList<int[]>>();
		for(int i=0; i<=N; i++) {
			graph.add(new ArrayList<int[]>());
		}
		
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			graph.get(u).add(new int[]{v, w});
			graph.get(v).add(new int[]{u, w});
		}
		
		st = new StringTokenizer(br.readLine());
		v1 = Integer.parseInt(st.nextToken());
		v2 = Integer.parseInt(st.nextToken());
		
		dijkstra(1);
		int sToV1 = distance[v1];
		int sToV2 = distance[v2];
		
		dijkstra(N);
		int V1ToN = distance[v1];
		int V2ToN = distance[v2];
		
		dijkstra(v1);
		int mid = distance[v2];

		int path1 = -1;
		int path2 = -1;
		if(sToV1 != Integer.MAX_VALUE && mid != Integer.MAX_VALUE && V2ToN != Integer.MAX_VALUE) {
			path1 = sToV1 + mid + V2ToN;
		}
		if(sToV2 != Integer.MAX_VALUE && mid != Integer.MAX_VALUE && V1ToN != Integer.MAX_VALUE) {
			path2 = sToV2 + mid + V1ToN;
		}
		
		if(path1 == -1 && path2 == -1) {
			System.out.println(-1);
		}
		else {
			System.out.println(Math.min(path1, path2));
		}
		
	}
	
	public static void dijkstra(int s) {
		distance = new int[N+1];
		Arrays.fill(distance, Integer.MAX_VALUE);
		
		PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
			if(o1[0] == o2[0]) {
				return Integer.compare(o1[1], o2[1]);
			}
			return Integer.compare(o1[0], o2[0]);
		});
		
		pq.add(new int[] {0, s});
		distance[s] = 0;
		while(!pq.isEmpty()) { //정점 개수만큼 반복
			int cur = pq.peek()[1];
			int w = pq.peek()[0]; //누적된 가중치
			pq.poll();
			
			if(w > distance[cur])
				continue;
			
			for(int[] next : graph.get(cur)) {
				int nextNode = next[0];
				int nextWeight = next[1];
				//1과 N도 여러 번 거쳐도 된다. 
				if(w + nextWeight < distance[nextNode]) {
					distance[nextNode] = w + nextWeight;
					pq.add(new int[] {w + nextWeight, nextNode});
				}
			}
			
		}
		
	}
}

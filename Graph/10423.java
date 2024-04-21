import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj10423 {
	
	static int N, M, K;
	static int [] plant;
	static boolean [] visited;
	static ArrayList<ArrayList<int[]>> graph;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); //도시의 개수
		M = Integer.parseInt(st.nextToken()); //간선 개수
		K = Integer.parseInt(st.nextToken()); //발전소 개수
		visited = new boolean[N+1];
		
		st = new StringTokenizer(br.readLine());
		plant = new int[K];
		for(int i=0; i<K; i++) {
			plant[i] = Integer.parseInt(st.nextToken());
		}
		
		graph = new ArrayList<ArrayList<int[]>>();
		for(int i=0; i<=N; i++) {
			graph.add(new ArrayList<int[]>());
		}
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			graph.get(u).add(new int[] {v, w});
			graph.get(v).add(new int[] {u, w});
		}
		
		//간선 가중치, 연결된 정점 번호
		PriorityQueue<int []> pq = new PriorityQueue<>((o1, o2) -> {
			if(o1[0] == o2[0]) {
				return Integer.compare(o1[1], o2[1]);
			}
			return Integer.compare(o1[0], o2[0]);
		});
		for(int i=0; i<K; i++) {
			int p = plant[i];
			visited[p] = true;
			for(int[] next : graph.get(p)) {
				int node = next[0];
				int w = next[1];
				pq.add(new int[] {w, node});
			}
		}
		
		int cost = 0;
		while(!pq.isEmpty()) {
			int node = pq.peek()[1];
			int weight = pq.peek()[0];
			pq.poll();
			
			if(visited[node])
				continue;
			
			visited[node] = true;
			cost += weight;
			for(int [] next : graph.get(node)) {
				int n = next[0];
				int w = next[1];
				if(!visited[n]) {
					pq.add(new int[] {w, n});
				}
			}
		}
		
		System.out.println(cost);
	}
}

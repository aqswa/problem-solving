import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj16398 {
	static int N;
	static int cost[][];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		cost = new int[N+1][N+1];
		for(int i=1; i<=N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=1; j<=N; j++) {
				cost[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		System.out.println(prim());
	}
	
	public static long prim() {
		PriorityQueue<int []> pq = new PriorityQueue<>((o1, o2) ->  {
			return Integer.compare(o1[0], o2[0]);
		});
		boolean visited[] = new boolean[N+1];

		pq.add(new int[] {0, 1}); //간선 가중치, 정점 번호
		long total = 0;
		int cnt = 0;
		while(!pq.isEmpty()) {
			int weight = pq.peek()[0];
			int cur = pq.peek()[1];
			pq.poll();
			
			if(visited[cur])
				continue;
			
			visited[cur] = true;
			total += weight;
			cnt++;
			
			for(int i=1; i<=N; i++) {
				if(!visited[i]) {
					pq.add(new int[] {cost[cur][i], i});
				}
			}
			
			if(cnt == N) {
				return total;
			}
		}
		
		return -1;
	}
}

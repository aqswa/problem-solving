import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj1368 {
	static int N;
	static int self [];
	static int cost[][];
	static int min = Integer.MAX_VALUE;
	static PriorityQueue<int []> pq = new PriorityQueue<int []>((o1, o2) -> {
		return Integer.compare(o1[0], o2[0]);
	});
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		self = new int[N];
		cost = new int[N][N];
		
		for(int i=0; i<N; i++) {
			self[i] = Integer.parseInt(br.readLine());
			pq.add(new int[] {self[i], i});
		}
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				cost[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		System.out.println(prim());
	}
	
	public static int prim() {
		boolean visited[] = new boolean[N];
		int total = 0;
		int cnt = 0;
		
		while(!pq.isEmpty()) {
			int cur = pq.peek()[1];
			int weight = pq.peek()[0];
			pq.poll();
			
			if(visited[cur])
				continue;
			
			total += weight;
			cnt++;
			visited[cur] = true;
			
			for(int i=0; i<N; i++) {
				if(!visited[i]) {
					pq.add(new int [] {cost[cur][i], i});
				}
			}
			
			if(cnt == N)
				break;
		}
		
		return total;
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj4485 {
	
	static int N;
	static int board[][];
	static int deltas[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = 0;
		while(true) {
			N = Integer.parseInt(br.readLine());
			if(N == 0) {
				break;
			}
			
			board = new int[N][N];
			
			int dp[][] = new int[N][N];
			
			for(int i=0; i<N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j=0; j<N; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
						
			sb.append("Problem " + (++T) + ": " + dijkstra() + "\n");
			
		}
		
		System.out.println(sb);
		

	}
	
	public static int dijkstra() {
		int [][] distance = new int[N][N];
		for(int i=0; i<N; i++) {
			Arrays.fill(distance[i], Integer.MAX_VALUE);
		}
		
		PriorityQueue<int []> pq = new PriorityQueue<>((o1, o2) -> {
			return Integer.compare(o1[0], o2[0]);
		});
		
		distance[0][0] = board[0][0];
		pq.add(new int[] {board[0][0], 0, 0});
		
		while(!pq.isEmpty()) {
			int weight = pq.peek()[0];
			int r = pq.peek()[1];
			int c = pq.peek()[2];
			pq.poll();
			
			if(distance[r][c] < weight) //이미 방문한 정점이라면
				continue;
			
			for(int i=0; i<4; i++) {
				int nr = r + deltas[i][0];
				int nc = c + deltas[i][1];
				if(nr >= 0 && nr < N && nc >= 0 && nc < N) {
					int next_weight = weight + board[nr][nc];
					if(next_weight < distance[nr][nc]) {
						distance[nr][nc] = next_weight;
						pq.add(new int[] {next_weight, nr, nc});
					}
				}
			}
		}
		
		return distance[N-1][N-1];
	}
}

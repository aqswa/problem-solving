import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj10971 {
	static int N;
	static int board[][];
	static int ans = Integer.MAX_VALUE;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		boolean [] visited = new boolean[N];
		for(int i=0; i<N; i++) {
			visited[i] = true;
			permutation(i, 1, visited, 0, i);
		}
		System.out.println(ans);
	}
	
	public static void permutation(int s, int cnt, boolean[] visited, int sum, int prev) {
		if(cnt == N) {
			if(board[prev][s] != 0) {
				sum += board[prev][s];
				if(sum < ans) {
					ans = sum;
				}
			}
			return;
		}
		
		for(int i=0; i<N; i++) {
			if(!visited[i] && board[prev][i] != 0) {
				visited[i] = true;
				permutation(s, cnt+1, visited, sum + board[prev][i], i);
				visited[i] = false;
			}
		}
	}
}

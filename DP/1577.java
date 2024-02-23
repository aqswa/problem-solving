import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj1577 {
	static int N, M;
	static boolean row[][];
	static boolean col[][];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		row = new boolean[M][N+1];
		col = new boolean[M+1][N];
		long dp[][] = new long [M+1][N+1];
		int K = Integer.parseInt(br.readLine());
		
		while(K-- != 0) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			
			if((a-c) != 0) { //col 도로가 없는 경우
				if(a > c) {
					col[b][c] = true;
				}
				else {
					col[b][a] = true;
				}
			}
			else if((b-d) != 0){ //row 도로가 없는 경우
				if(b > d) {
					row[d][a] = true;
				}
				else {
					row[b][a] = true;
				}
			}
		}
		
		dp[0][0] = 1;
		for(int i=1; i<=N; i++) {
			if(col[0][i-1]) { //막힌 길이라면
				dp[0][i] = 0;
			}
			else {
				dp[0][i] = dp[0][i-1];
			}
		}
		
		for(int i=1; i<=M; i++) {
			if(row[i-1][0]) {
				dp[i][0] = 0;
			}
			else {
				dp[i][0] = dp[i-1][0];
			}
		}
		
		for(int i=1; i<=M; i++) {
			for(int j=1; j<=N; j++) {
				if(row[i-1][j] && col[i][j-1]) {
					dp[i][j] = 0;
				}
				else if(row[i-1][j]) {
					dp[i][j] = dp[i][j-1];
				}
				else if(col[i][j-1]) {
					dp[i][j] = dp[i-1][j];
				}
				else {
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				}
			}
		}
		
		System.out.println(dp[M][N]);
	}
}

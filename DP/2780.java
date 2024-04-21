import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
				
		while(T-- != 0) {
			int N = Integer.parseInt(br.readLine());
			int dp[][] = new int[N+1][10];
			for(int i=0; i<10; i++) {
				dp[1][i] = 1;
			}
			
			for(int i=2; i<=N; i++) {
				dp[i][0] = dp[i-1][7] % 1234567;
				dp[i][1] = (dp[i-1][2] + dp[i-1][4]) % 1234567;
				dp[i][2] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][5]) % 1234567;
				dp[i][3] = (dp[i-1][2] + dp[i-1][6]) % 1234567;
				dp[i][4] = (dp[i-1][1] + dp[i-1][5] + dp[i-1][7]) % 1234567;
				dp[i][5] = (dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8]) % 1234567;
				dp[i][6] = (dp[i-1][3] + dp[i-1][5] + dp[i-1][9]) % 1234567;
				dp[i][7] = (dp[i-1][4] + dp[i-1][8] + dp[i-1][0]) % 1234567;
				dp[i][8] = (dp[i-1][5] + dp[i-1][7] + dp[i-1][9]) % 1234567;
				dp[i][9] = (dp[i-1][6] + dp[i-1][8]) % 1234567;
			}
			
			int ans = 0;
			for(int i=0; i<10; i++) {
				ans = (ans + dp[N][i]) % 1234567;
			}
			
			sb.append(ans).append("\n");
		}
		
		System.out.println(sb);
	}
}

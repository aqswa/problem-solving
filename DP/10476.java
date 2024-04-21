import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()); //세로 길이
		int K = Integer.parseInt(st.nextToken()); //닫아야 하는 방의 수
		
		int rooms[][] = new int[N][2];
		int total = 0;
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			rooms[i][0] = Integer.parseInt(st.nextToken());
			rooms[i][1] = Integer.parseInt(st.nextToken());
			total += (rooms[i][0] + rooms[i][1]);
		}
		
		int dp[][][] = new int[N][2][K+1];
		for(int i=0; i<N; i++) {
			dp[i][0][0] = total;
			dp[i][1][0] = total;
		}
		
		if(K != 0) {
			for(int i=0; i<N; i++) {
				dp[i][0][1] = total - rooms[i][0];
				dp[i][1][1] = total - rooms[i][1];
			}
		}
		
		for(int i=1; i<N; i++) {
			for(int k=1; k<=K; k++) {
				int max = 0;
				for(int j=0; j<i-1; j++) {
					max = Math.max(max, Math.max(dp[j][0][k-1], dp[j][1][k-1]));
				}
				
				dp[i][0][k] = Math.max(max, dp[i-1][0][k-1]) - rooms[i][0];
				dp[i][1][k] = Math.max(max, dp[i-1][1][k-1]) - rooms[i][1];
			}
		}
		
		int ans = 0;
		for(int i=0; i<N; i++) {
			ans = Math.max(ans, Math.max(dp[i][0][K], dp[i][1][K]));
		}
		
		System.out.println(ans);
	}
}

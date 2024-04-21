import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken()); //최대 공부시간
		int K = Integer.parseInt(st.nextToken()); //과목 수
		
		int subjects[][] = new int[K+1][2];
		for(int i=1; i<=K; i++) {
			st = new StringTokenizer(br.readLine());
			subjects[i][0] = Integer.parseInt(st.nextToken()); //중요도
			subjects[i][1] = Integer.parseInt(st.nextToken()); //소요 시간
		}
		
		int dp[][] = new int[K+1][N+1];
		for(int i=1; i<=K; i++) {
			for(int j=0; j<=N; j++) {
				if(j-subjects[i][1] >= 0) {
					dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-subjects[i][1]] + subjects[i][0]);
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		
		System.out.println(dp[K][N]);
	}
}

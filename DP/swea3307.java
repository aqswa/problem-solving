import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea3307 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		for(int t=1; t<=T; t++) {
			int N = Integer.parseInt(br.readLine());
			int numbers[] = new int[N];
			int dp[] = new int[N]; 
			Arrays.fill(dp, 1); //증가 수열 최소 길이 1로 초기화
			int ans = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0; i<N; i++) {
				numbers[i] = Integer.parseInt(st.nextToken());
				for(int j=i-1; j>=0; j--) { //이전 모든 수에 대해
					//이전 수가 현재 수보다 더 작고, 증가 수열의 길이가 더 길다면
					if(numbers[j] < numbers[i] && dp[j] + 1 > dp[i]) {
						dp[i] = dp[j] + 1;
					}
				}
				
				if(dp[i] > ans) {
					ans = dp[i];
				}
			}
			
			sb.append("#" + t + " " + ans + "\n");
		}
		
		System.out.println(sb);
	}
}

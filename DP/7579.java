import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj7579 {
	
	static int N, M;
	static int memory[];
	static int cost[];
	static int total = 0;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		memory = new int[N];
		cost = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			memory[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			cost[i] = Integer.parseInt(st.nextToken());
			total += cost[i]; //정해진 최대 비용(배낭의 최대 무게)가 없으므로 비용의 총합이 최대 비용
		}
		
		int dp[] = new int[total+1]; //각 비용으로 만들 수 있는 최대 가치
		Arrays.fill(dp, 0);
		
		for(int i=0; i<N; i++) { //1차원 냅색: 각 비용 별 최대 가치
			for(int j=total; j>=cost[i]; j--) {
				dp[j] = Math.max(dp[j], dp[j-cost[i]] + memory[i]);
			}
		}
		
		for(int i=0; i<=total; i++) { //메모리 60 넘는 최소 비용 출력
			if(dp[i] >= M) {
				System.out.println(i);
				break;
			}
		}
		
	}
}

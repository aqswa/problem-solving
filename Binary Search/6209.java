import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj6209 {
	
	static int N, M, D;
	static int [] islands;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		D = Integer.parseInt(st.nextToken()); //탈출구까지의 거리
		N = Integer.parseInt(st.nextToken()); //작은 돌섬 수
		M = Integer.parseInt(st.nextToken()); //제거할 수 있는 돌섬 수
		
		islands = new int[N+2];
		islands[0] = 0;
		islands[1] = D;
		for(int i=2; i<N+2; i++) {
			islands[i] = Integer.parseInt(br.readLine());
		}
		
		Arrays.sort(islands);
		
		int left = 0;
		int right = D;
		int ans = 0;
		while(left <= right) {
			int mid = (left + right) / 2;
			
			int cur = 0; //제멀하기 전 위치
			int cnt = 0;
			for(int i=1; i<=N; i++) {
				if(islands[i] - islands[cur] < mid) {
					cnt++;
				}
				else {
					cur = i;
				}
			}
			
			if(cnt > M) {
				right = mid - 1;
			}
			else {
				ans = mid;
				left = mid + 1;
			}
		}
		
		System.out.println(ans);
	}
}

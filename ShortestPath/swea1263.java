import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea1263 {
	static int N;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken()); //노드의 개수
			
			int [][] distance = new int[N][N];
			for(int i=0; i<N; i++) {
				Arrays.fill(distance[i], Integer.MAX_VALUE);
			}
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					distance[i][j] = Integer.parseInt(st.nextToken()) == 1 ? 1 : 1000;
				}
			}
			
			for(int i=0; i<N; i++) {
				distance[i][i] = 0;
			}
			
			for(int k=0; k<N; k++) {
				for(int i=0; i<N; i++) {
					for(int j=0; j<N; j++) {
						if(distance[i][k] + distance[k][j] < distance[i][j]) {
							distance[i][j] = distance[i][k] + distance[k][j];
						}
					}
				}
			}
			
			int min = Integer.MAX_VALUE;
			for(int i=0; i<N; i++) {
				int sum = 0;
				for(int j=0; j<N; j++) {
					sum += distance[i][j];
				}
				if(sum < min) {
					min = sum;
				}
			}
		
			sb.append("#" + t + " " + min + "\n");
		}
		
		System.out.println(sb);
	}
}

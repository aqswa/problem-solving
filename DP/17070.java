import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());
	
		int N = Integer.parseInt(st.nextToken());
		int board[][] = new int[N][N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int dp1[][] = new int[N][N]; // 가로
		int dp2[][] = new int[N][N]; // 세로
		int dp3[][] = new int[N][N]; // 대각선
		dp1[0][1] = 1;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(board[i][j] == 1)
					continue;
				if(i-1 >= 0) {
					if(board[i-1][j] != 1) {
						dp2[i][j] += dp2[i-1][j];
						dp2[i][j] += dp3[i-1][j];
					}
				}
				if(j-1 >= 0) {
					if(board[i][j-1] != 1) {
						dp1[i][j] += dp1[i][j-1];
						dp1[i][j] += dp3[i][j-1];
					}
				}
				if(i-1 >= 0 && j-1 >= 0 && board[i-1][j] != 1 && board[i][j-1] != 1) {
					if(board[i-1][j-1] != 1) {
						dp3[i][j] += (dp1[i-1][j-1] + dp2[i-1][j-1] + dp3[i-1][j-1]);
					}
				}
			}
		}
		
		System.out.println(dp1[N-1][N-1] + dp2[N-1][N-1] + dp3[N-1][N-1]);
	}
}

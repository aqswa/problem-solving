import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea5656 {
	static int N, W, H;
	static int board[][];
	static int ans;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			ans = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			
			board = new int[H][W];
			
			int total = 0;
			for(int i=0; i<H; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<W; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
					if(board[i][j] != 0) {
						total++;
					}
				}
			}
			
			dfs(0, 0);
			
			sb.append("#" + t + " " + (total - ans) + "\n");
		}
		
		System.out.println(sb);
	}	  
 	
	public static void dfs(int cnt, int sum) {
		if(cnt == N) {
			if(sum > ans) {
				ans = sum;
			}
			
			return;
		}
		
		for(int i=0; i<W; i++) { //구슬 던질 열 선택
			int [][] temp = new int[H][W];
			for(int j=0; j<H; j++) {
				temp[j] = board[j].clone();
			}
			int remove = removeBlock(i);
			dfs(cnt+1, sum + remove);
			for(int j=0; j<H; j++) {
				board[j] = temp[j].clone();
			}
		}
	}
	
	public static int removeBlock(int col) {
		
		int removedCnt = 0;
		for(int i=0; i<H; i++) {
			if(board[i][col] != 0) {
				removedCnt = recursive(i, col);
				break;
			}
		}
		
		moveBlock();
		
		return removedCnt;
	}
	
	public static int recursive(int r, int c) {
		if(r < 0 || r >= H || c < 0 || c >= W) {
			return 0;
		}
		
		if(board[r][c] == 0) {
			return 0;
		}
		
		if(board[r][c] == 1) {
			board[r][c] = 0;
			return 1;
		}
		
		int range = board[r][c] - 1;
		board[r][c] = 0;
		int sum = 1;
		for(int i=(-range); i<=range; i++) {
			sum += recursive(r + i, c);
			sum += recursive(r, c + i);
		}
		
		return sum;
	}
	
	public static void moveBlock() {
		for(int i=0; i<W; i++) {
			int top = H;
			for(int j=H-1; j>=0; j--) {
				if(board[j][i] != 0) {
					board[--top][i] = board[j][i];
					if(j != top) {
						board[j][i] = 0;
					}
				}
			}
		}
	}
}

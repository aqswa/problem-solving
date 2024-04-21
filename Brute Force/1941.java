import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class boj1941 {

	static int board[][] = new int[5][5];
	static boolean visited[][] = new boolean[5][5];
	static int ans;
	static int deltas[][] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for(int i=0; i<5; i++) {
			String s = br.readLine();
			for(int j=0; j<5; j++) {
				board[i][j] = s.charAt(j);
			}
		}
		
		combination(0, 0, 0);
		
		System.out.println(ans);
	}
	
	public static void combination(int last, int idx, int cnt) {
		if(cnt == 7) {
			if(check(last)) {
				ans++;
			}
			return;
		}
		
		for(int i=idx; i<25; i++) {
			int r = i/5;
			int c = i%5;
			visited[r][c] = true;
			combination(i, i+1, cnt+1);
			visited[r][c] = false;
		}
	}
	
	public static boolean check(int idx) {
		
		boolean visit[][] = new boolean[5][5];
		Queue<int []> q = new ArrayDeque<>();
		q.add(new int [] {idx/5, idx%5});
		visit[idx/5][idx%5] = true;
		int y = 0;
		int s = 0;
		if(board[idx/5][idx%5] == 'Y') {
			y++;
		}
		else {
			s++;
		}
		
		while(!q.isEmpty()) {
			int r = q.peek()[0];
			int c = q.peek()[1];
			q.poll();
			
			for(int i=0; i<4; i++) {
				int nr = r + deltas[i][0];
				int nc = c + deltas[i][1];
				//이전에 방문한 적 없고, 조합에서 선택한 칸이라면
				if(nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && !visit[nr][nc] && visited[nr][nc]) {
					if(board[nr][nc] == 'Y') {
						y++;
					}
					else if(board[nr][nc] == 'S') {
						s++;
					}
					visit[nr][nc] = true;
					q.add(new int [] {nr, nc});
				}
			}
		}
		
		//System.out.println(y + " " + s);
		
		if((y + s) == 7 && s > y) {
			return true;
		}
		else {
			return false;
		}
	}
}

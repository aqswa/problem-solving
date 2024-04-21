import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int R, C;
	static char board[][];
	static int deltas[][] = {{-1, 1}, {0, 1}, {1, 1}}; //오른쪽 위, 오른쪽, 오른쪽 아래
	static int ans = 0;
	static boolean visited[][];
	static boolean path_flag;
	public static void find_path(int r, int c) {
		if(c == C-1) {
			path_flag = true;
			return;
		}
		
		for(int i=0; i<3; i++) {
			int nr = r + deltas[i][0];
			int nc = c + 1;
			if(nr >= 0 && nr < R && nc >= 0 && nc < C && board[nr][nc] != 'x' && visited[nr][nc] == false) {
				if(i == 0) { //없어도 됨
					if(!visited[nr+1][nc]) { //오른쪽 아래를 방문했다면 오른쪽 위로 갔던 경로가 실패한 경우이므로 확인할 필요 x
						find_path(nr, nc);
						visited[nr][nc] = true;
					}
				}
				else {
					find_path(nr, nc);
					visited[nr][nc] = true;
				}
				if(path_flag == true) {
					break;
				}
			}
		}
	}
	
	public static void dfs(int r, int cnt) {
		if(r == R-1) {
			if(cnt > ans) {
				ans = cnt;
			}
			return;
		}
		
		path_flag = false;
		find_path(r, 0);
		if(path_flag) {
			dfs(r+1, cnt+1);
		}
		else {
			dfs(r+1, cnt);
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		visited = new boolean [R][C];
		board = new char [R][C];
		for(int i=0; i<R; i++) {
			String s = br.readLine();
			for(int j=0; j<C; j++) {
				board[i][j] = s.charAt(j);
			}
		}
		
		dfs(0, 0);
		
		System.out.println(ans);
	}

}

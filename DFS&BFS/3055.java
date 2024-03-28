import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj3055 {
	
	static int R, C;
	static char board[][];
	static int deltas[][] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	static int water[][];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		board = new char[R][C];
		water = new int[R][C];
		
		ArrayList<int []> waterStart = new ArrayList<>();
		
		int hedgeR = 0, hedgeC = 0;
		for(int i=0; i<R; i++) {
			String s = br.readLine();
			for(int j=0; j<C; j++) {
				board[i][j] = s.charAt(j);
				if(board[i][j] == 'S') { //고슴도치 시작 위치
					hedgeR = i;
					hedgeC = j;
				} else if(board[i][j] == '*') {
					waterStart.add(new int[] {i, j});
				}
			}
		}
		
		for(int i=0; i<R; i++) {
			Arrays.fill(water[i], -1);
		}
		
		for(int [] w : waterStart) {
			water_bfs(w[0], w[1]);
		}
		
		int ans = hedge_bfs(hedgeR, hedgeC);
		if(ans == -1) {
			System.out.println("KAKTUS");
		} else {
			System.out.println(ans);
		}
	}
	
	public static void water_bfs(int sr, int sc) {
		Queue<int []> q = new ArrayDeque<>();
		q.add(new int[] {sr, sc, 0});
		water[sr][sc] = 0;
		
		while(!q.isEmpty()) {
			int r = q.peek()[0];
			int c = q.peek()[1];
			int cnt = q.peek()[2];
			q.poll();
			
			for(int i=0; i<4; i++) {
				int nr = r + deltas[i][0];
				int nc = c + deltas[i][1];
				if(nr >= 0 && nr < R && nc >= 0 && nc < C && board[nr][nc] != 'D' && board[nr][nc] != 'X') {
					if(water[nr][nc] == -1 || water[nr][nc] > cnt + 1) { //물이 찬 적 없거나 이전 탐색에서 물이 더 늦게 찼었다면
						water[nr][nc] = cnt + 1;
						q.add(new int[] {nr, nc, cnt + 1});
					}
				}
			}
			
		}
	}
	
	public static int hedge_bfs(int sr, int sc) {
		boolean [][] visited = new boolean[R][C];
		visited[sr][sc] = true;
		Queue<int []> q = new ArrayDeque<>();
		q.add(new int[] {sr, sc, 0});
		
		while(!q.isEmpty()) {
			int r = q.peek()[0];
			int c = q.peek()[1];
			int cnt = q.peek()[2];
			q.poll();
			
			for(int i=0; i<4; i++) {
				int nr = r + deltas[i][0];
				int nc = c + deltas[i][1];
				
				if(nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc] && board[nr][nc] != 'X') {
					visited[nr][nc] = true;
					if(board[nr][nc] == 'D') { //비버의 굴에 도달하면 시간 리턴. bfs는 가장 먼저 도달한 시간이 최단시간
						return cnt + 1;
					}
					
					if(water[nr][nc] == -1 || water[nr][nc] > cnt + 1) { //물이 더 늦게 도달하는 칸이라면
						q.add(new int[] {nr, nc, cnt + 1});
					}
				}
			}
		}
		
		return -1;
	}
}

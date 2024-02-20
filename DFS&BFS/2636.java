package d0220;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj2636 {
	
	static int N, M;
	static boolean board[][];
	static ArrayList<int []> remove;
	static int lastCnt, time;
	static int deltas[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	public static void bfs() {
		boolean visited[][] = new boolean[N][M];
		Queue<int []> q = new ArrayDeque<>();
		
		q.add(new int[] {0, 0});
		visited[0][0] = true;
		
		while(!q.isEmpty()) {
			int [] cur = q.poll();
			int r = cur[0];
			int c = cur[1];
			
			for(int k=0; k<4; k++) {
				int nr = r + deltas[k][0];
				int nc = c + deltas[k][1];
				if(nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc]) {
					visited[nr][nc] = true;
					if(board[nr][nc] == false) {
						q.add(new int[] {nr, nc});
					}
					else {
						remove.add(new int[] {nr, nc});
					}
				}
			}
		}
	}
	
	public static int countCheese() {
		int cnt = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(board[i][j] == true) {
					cnt++;
				}
			}
		}
		
		return cnt;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new boolean[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken()) == 0 ? false : true;
			}
		}

		lastCnt = countCheese(); //1시간만에 치즈가 사라지는 테스트 케이스가 있음
		while(true) {
			remove = new ArrayList<>();
			bfs();
			for(int [] coord : remove) {
				board[coord[0]][coord[1]] = false;
			}
			
			time++;
			int cnt = countCheese();
			if(cnt == 0) {
				System.out.println(time);
				System.out.println(lastCnt);
				break;
			}
			else {
				lastCnt = cnt;
			}
		}
		
	}
}

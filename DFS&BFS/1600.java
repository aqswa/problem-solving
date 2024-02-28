//출처: https://yabmoons.tistory.com/48

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int K, N, M;
	static int delta[][] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	static int deltaH[][] = {{-2, -1}, {-1, -2}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};
	static boolean visited[][][];
	static int board[][];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		K = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());

		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		visited = new boolean[N][M][K+1];
		
		bfs();
	}
	
	public static void bfs() {
		Queue<int []> q = new ArrayDeque<int[]>();
		q.add(new int[] {0, 0, 0, 0});
		visited[0][0][0] = true;
		while(!q.isEmpty()) {
			int r = q.peek()[0];
			int c = q.peek()[1];
			int move = q.peek()[2];
			int k = q.peek()[3];
			
			if(r == N-1 && c == M-1) {
				System.out.println(move);
				return;
			}
			
			q.poll();
			
			if(k < K) {
				for(int i=0; i<8; i++) {
					int nr = r + deltaH[i][0];
					int nc = c + deltaH[i][1];
					if(nr >= 0 && nr < N && nc >= 0 && nc < M) {
						if(!visited[nr][nc][k+1] && board[nr][nc] != 1) {
							visited[nr][nc][k+1] = true;
							q.add(new int[] {nr, nc, move+1, k+1});
						}
					}
				}
			}
			
			for(int i=0; i<4; i++) {
				int nr = r + delta[i][0];
				int nc = c + delta[i][1];
				if(nr >= 0 && nr < N && nc >= 0 && nc < M && board[nr][nc] != 1) {
					if(!visited[nr][nc][k]) {
						visited[nr][nc][k] = true;
						q.add(new int[] {nr, nc, move+1, k});
					}
				}
			}
		}
		
		System.out.println(-1);
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[][] board;
	static int deltas[][] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	static int shark = 2; //상어 크기
	static int fr, fc, dist; //물고기 위치, 거리
	public static void findFish(int sr, int sc) {
		boolean [][] visited = new boolean[N][N];
		visited[sr][sc] = true;
		
		Queue<int []> q = new ArrayDeque<int[]>();
		q.add(new int[] {sr, sc, 0});
		
		PriorityQueue<int []> pq = new PriorityQueue<>((o1, o2) ->  {
			if(o1[0] == o2[0]) {
				if(o1[1] == o2[1]) {
					return Integer.compare(o1[2], o2[2]);
				}
				return Integer.compare(o1[1], o2[1]);
			}
			return Integer.compare(o1[0], o2[0]);
		});
		
		while(!q.isEmpty()) {
			int r = q.peek()[0];
			int c = q.peek()[1];
			int cnt = q.peek()[2];
			q.poll();
			
			for(int i=0; i<4; i++) {
				int nr = r + deltas[i][0];
				int nc = c + deltas[i][1];
				if(nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
					if(board[nr][nc] <= shark) {
						visited[nr][nc] = true;
						q.add(new int [] {nr, nc, cnt+1});
						if(board[nr][nc] < shark && board[nr][nc] != 0) {
							pq.add(new int[] {cnt+1, nr, nc});
						}
					}
				}
			}
		}
		
		if(pq.isEmpty()) {
			dist = -1;
		}
		else {
			dist = pq.peek()[0];
			fr = pq.peek()[1];
			fc = pq.peek()[2];
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		int sr = 0, sc = 0; //상어의 위치
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j] == 9) {
					sr = i;
					sc = j;
				}
			}
		}
		
		int time = 0;
		int eat = 0; //상어 크기 커진 이후로 먹은 물고기 수
		while(true) {
			findFish(sr, sc);
			if(dist == -1) {
				break;
			}
			
			board[sr][sc] = 0;
			board[fr][fc] = 9;
			sr = fr;
			sc = fc;
			eat++;
			time += dist;
			
			if(eat == shark) {
				shark++;
				eat = 0;
			}
		}
		
		System.out.println(time);
	}
}

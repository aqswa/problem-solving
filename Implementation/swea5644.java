import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	static int M, A; //총 이동 시간, BC의 개수
	static int move[][];
	static ArrayList<ArrayList<Integer>> board;
	static int perf[];
	static int deltas[][] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //이동안함, 상, 우, 좌, 하
	static boolean visited[][];
	static int ans = 0;
	
	public static void bfs(int bc, int sx, int sy, int C) { //bc 인덱스, 현재 좌표, bc 범위, 현재 이동 범위
		Queue<int[]> q = new ArrayDeque<int[]>();
		visited[sx][sy] = true;
		q.add(new int[] {sx, sy, 0});
		board.get(10 * (sx-1) + sy).add(bc);
		while(!q.isEmpty()) {
			int x = q.peek()[0];
			int y = q.peek()[1];
			int cnt = q.peek()[2];
			q.poll();
			for(int i=1; i<=4; i++) {
				int nx = x + deltas[i][0];
				int ny = y + deltas[i][1];
				if(nx >= 1 && nx <= 10 && ny >= 1 && ny <= 10 && !visited[nx][ny] && cnt < C) {
					q.add(new int[] {nx, ny, cnt+1});
					visited[nx][ny] = true;
					board.get(10*(nx-1) + ny).add(bc);
				}
			}
		}
	}
	
	public static int find_max(int ax, int ay, int bx, int by) {
		ArrayList<Integer> arrA = board.get(10*(ax-1) + ay);
		ArrayList<Integer> arrB = board.get(10*(bx-1) + by);
		
		int sum = 0;
		if(arrA.size() == 0 && arrB.size() > 0) {
			for(int i=0; i<arrB.size(); i++) {
				sum = Math.max(sum, perf[arrB.get(i)]);
			}
		}
		else if(arrB.size() == 0 && arrA.size() > 0) {
			for(int i=0; i<arrA.size(); i++) {
				sum = Math.max(sum, perf[arrA.get(i)]);
			}
		}
		else if(arrA.size() > 0 && arrB.size() > 0) {
			for(int i=0; i<arrA.size(); i++) {
				int bcA = arrA.get(i);
				for(int j=0; j<arrB.size(); j++) {
					int bcB = arrB.get(j);
					if(bcA == bcB) {
						sum = Math.max(sum, perf[bcA]);
					}
					else {
						sum = Math.max(sum, perf[bcA] + perf[bcB]);
					}
				}
			}
		}
		return sum;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken()); //이동 시간
			A = Integer.parseInt(st.nextToken()); //BC의 개수
			
			//초기화
			perf = new int [A]; //BC의 성능
			move = new int[2][M]; //이동 경로
			ans = 0;
			for(int i=0; i<2; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<M; j++) {
					move[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			board = new ArrayList<>();
			for(int i=0; i<=100; i++) { //10x10 보드
				board.add(new ArrayList<>());
			}

			for(int i=0; i<A; i++) {
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				int C = Integer.parseInt(st.nextToken()); //충전 범위
				perf[i] = Integer.parseInt(st.nextToken()); //성능
				
				visited = new boolean[11][11];
				bfs(i, x, y, C); //보드에 충전 범위 저장
			}

			int ax = 1;
			int ay = 1;
			int bx = 10;
			int by = 10;
			for(int i=0; i<M; i++) {
				ans += find_max(ax, ay, bx, by);
				ax += deltas[move[0][i]][0];
				ay += deltas[move[0][i]][1];
				bx += deltas[move[1][i]][0];
				by += deltas[move[1][i]][1];	
			}
			ans += find_max(ax, ay, bx, by);
			
			sb.append("#").append(t).append(" ").append(ans).append("\n");
		}
		
		System.out.println(sb);
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea2383 {
	static int N;
	static int board[][];
	static int ar, ac, ak, br, bc, bk;
	static ArrayList<int []> people;
	static int [] door1 = new int[10]; //각 문마다 사람이 도착하는 분(minute)
	static int [] door2 = new int[10];
	static int min;
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(in.readLine());

		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(in.readLine());
			board = new int[N][N];
			people = new ArrayList<>();
			min = Integer.MAX_VALUE;
			//사람, 문 위치와 길이 입력
			int door = 0;
			for(int i=0; i<N; i++) {
				StringTokenizer st = new StringTokenizer(in.readLine());
				for(int j=0; j<N; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
					if(board[i][j] > 1) {
						if(door == 0) {
							ar = i;
							ac = j;
							ak = board[i][j];
							door++;
						}
						else if(door == 1) {
							br = i;
							bc = j;
							bk = board[i][j];
						}
					}
					else if(board[i][j] == 1){
						people.add(new int[] {i, j});
					}
				}
			}
			
			dfs(0, 0);
			sb.append("#" + t + " " + min + "\n");
		}
		System.out.println(sb);
	}
	
	public static void dfs(int cnt1, int cnt2) {
		if(cnt1 + cnt2 == people.size()) {
			int time = stairDown(cnt1, cnt2);
			if(time < min) {
				min = time;
			}
			return;
		}
		
		int r = people.get(cnt1 + cnt2)[0];
		int c = people.get(cnt1 + cnt2)[1];
		int dist = Math.abs(r - ar) + Math.abs(c - ac);
		door1[cnt1] = dist;
		dfs(cnt1+1, cnt2);
		
		dist = Math.abs(r - br) + Math.abs(c - bc);
		door2[cnt2] = dist;
		dfs(cnt1, cnt2+1);
	}
	
	public static int stairDown(int cnt1, int cnt2) {
		int time = 0;
		
		int door1Copy[] = new int [cnt1];
		int door2Copy[] = new int [cnt2];
		for(int i=0; i<cnt1; i++) {
			door1Copy[i] = door1[i];
		}
		for(int i=0; i<cnt2; i++) {
			door2Copy[i] = door2[i];
		}
		
		Arrays.sort(door1Copy);
		Arrays.sort(door2Copy);
		
		int [] stair = new int[1000];
		int idx = 0;
		for(int i=0; i<cnt1; i++) {
			idx = door1Copy[i] + 1; //i번째로 도착한 사람이 계단 내려가기 시작할 수 있는 시간
			while(stair[idx] >= 3) {
				idx++;
			}
			
			for(int j=0; j<ak; j++) {
				stair[idx + j]++;
			}
		}
		time = idx + ak;
		
		stair = new int[1000];
		for(int i=0; i<cnt2; i++) {
			idx = door2Copy[i] + 1;
			while(stair[idx] >= 3) {
				idx++;
			}
			
			for(int j=0; j<bk; j++) {
				stair[idx + j]++;
			}
			
			if(idx + bk > time) {
				time = idx + bk;
			}
		}
		
		return time;
	}
}

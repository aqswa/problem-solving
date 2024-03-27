import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class boj2239 {
	
	static ArrayList<Set<Integer>> row = new ArrayList<Set<Integer>>();
	static ArrayList<Set<Integer>> col = new ArrayList<Set<Integer>>();
	static ArrayList<Set<Integer>> box = new ArrayList<Set<Integer>>();
	static int board[][] = new int[9][9];
	static ArrayList<int[]> blank = new ArrayList<int[]>();
	static boolean flag = false;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<9; i++) {
			row.add(new HashSet<Integer>());
			col.add(new HashSet<Integer>());
			box.add(new HashSet<Integer>());
		}
		
		for(int i=0; i<9; i++) {
			String s = br.readLine();
			for(int j=0; j<9; j++) {
				board[i][j] = s.charAt(j) - '0';
				if(board[i][j] != 0) {
					row.get(i).add(board[i][j]);
					col.get(j).add(board[i][j]);
					int r = i/3; int c = j/3;
					box.get(r*3 + c).add(board[i][j]);
				} else {
					blank.add(new int[] {i, j});
				}
			}
		}
		
		dfs(0);
		
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				sb.append(board[i][j]);
			}
			sb.append("\n");
		}
		
		System.out.println(sb);
	}
	
	public static void dfs(int cnt) {
		if(cnt == blank.size()) {
			flag = true;
			return;
		}
		
		int [] coord = blank.get(cnt);
		int r = coord[0];
		int c = coord[1];
		
		for(int n=1; n<=9; n++) {
			if(row.get(r).contains(n)) continue;
			if(col.get(c).contains(n)) continue;
			int boxR = r/3; int boxC = c/3;
			if(box.get(boxR*3 + boxC).contains(n)) continue;
			
			row.get(r).add(n); col.get(c).add(n); box.get(boxR*3 + boxC).add(n);
			board[r][c] = n;
			dfs(cnt+1);
			
			if(flag)
				return;
			
			board[r][c] = 0;
			row.get(r).remove(n); col.get(c).remove(n); box.get(boxR*3 + boxC).remove(n);
			
		}
	}
	
}

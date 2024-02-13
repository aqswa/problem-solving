import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 규영이와인영이의카드게임 {
	static int [] kyuyoung = new int[9];
	static int [] inyoung = new int[9];
	static int win, loose;
	
	public static void calc_score() {
		int kyu = 0;
		int in = 0;
		for(int i=0; i<9; i++) {
			if(kyuyoung[i] > inyoung[i]) {
				kyu += (kyuyoung[i] + inyoung[i]);
			}
			else {
				in += (kyuyoung[i] + inyoung[i]);
			}
		}
		
		if(kyu > in) {
			win++;
		}
		else {
			loose++;
		}
	}
	
	public static boolean next_permutation(int [] p) {
		int N = p.length;
		
		int i = N-1;
		while(i > 0 && p[i-1] >= p[i]) --i;
		
		if(i == 0) return false;
		
		int j = N-1;
		while(p[i-1] >= p[j]) --j; //바꿀 값보다 큰 값 중 가장 작은 값 찾기
		
		swap(p, i-1, j);
		
		int k = N-1;
		while(i<k) swap(p, i++, k--);
		
		return true;
	}
	
	public static void swap(int [] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		for(int t=1; t<=T; t++) {
			boolean [] used = new boolean[19];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0; i<9; i++) {
				kyuyoung[i] = Integer.parseInt(st.nextToken());
				used[kyuyoung[i]] = true;
			}
			
			int idx = 0;
			for(int i=1; i<19; i++) {
				if(!used[i]) {
					inyoung[idx++] = i;
				}
			}
			
			win = 0;
			loose = 0;
			
			Arrays.sort(inyoung);
			do {
				calc_score();
			}while(next_permutation(inyoung));
			
			sb.append("#").append(t).append(" ").append(win).append(" ").append(loose).append("\n");
		}
		
		System.out.println(sb);
	}
}

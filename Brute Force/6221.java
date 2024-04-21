import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int bales[][];
	static int ans = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine()); //건초 개수
		bales = new int[N][2];
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			bales[i][0] = Integer.parseInt(st.nextToken());
			bales[i][1] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(bales, (o1, o2) -> {
			return Integer.compare(o1[0], o2[0]);
		});
		
		combination(0, 0, 0);
		
		System.out.println(ans);
	}
	
	public static void combination(int idx, int cnt, int width) {
		if(idx == N) {
			if(cnt > ans) {
				ans = cnt;
			}
			return;
		}
		
		for(int i=idx; i<N; i++) {
			if(bales[i][1] > width) {
				combination(i+1, cnt+1, bales[i][1]);
			}
			combination(i+1, cnt, width);
		}
	}
}

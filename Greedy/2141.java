import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj2141 {
	
	static long town [][];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		town = new long [N][2];
		long total = 0;
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			town[i][0] = Long.parseLong(st.nextToken());
			town[i][1] = Long.parseLong(st.nextToken());
			total += town[i][1];
		}
		
		Arrays.sort(town, (o1, o2) -> {
			return Long.compare(o1[0], o2[0]);
		});
		
		long now = 0;
		for(int i=0; i<N; i++) {
			now += town[i][1];
			if(now >= (total+1)/2) {
				System.out.println(town[i][0]);
				break;
			}
		}
		
	}
}

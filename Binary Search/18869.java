import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static int ans = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); //우주의 개수
		M = Integer.parseInt(st.nextToken()); //행성의 개수
		
		int planets[] = new int[M];
		int sorted[] = new int[M];
		int compressed[][] = new int[N][M];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				planets[j] = Integer.parseInt(st.nextToken());
			}
		
			sorted = Arrays.stream(planets).distinct().sorted().toArray();
			
			for(int j=0; j<M; j++) {
				//sorted에서 arr[j]의 위치를 찾아서 인덱스 반환
				compressed[i][j] = Arrays.binarySearch(sorted, planets[j]);
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=i+1; j<N; j++) {
				if(Arrays.equals(compressed[i], compressed[j])) {
					ans++;
				}
			}
		}
		
		
		System.out.println(ans);
	}

}

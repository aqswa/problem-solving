import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static int N;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		
		//꽃이 진 날짜
		int month = 3;
		int day = 1;
		
		//빨리 피는 순으로 정렬
		PriorityQueue<int []> pq = new PriorityQueue<>((o1, o2) -> {
			if(o1[0] == o2[0]) {
				return Integer.compare(o1[1], o2[1]);
			}
			return Integer.compare(o1[0], o2[0]);
		});
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int smonth = Integer.parseInt(st.nextToken());
			int sday = Integer.parseInt(st.nextToken());
			int emonth = Integer.parseInt(st.nextToken());
			int eday = Integer.parseInt(st.nextToken());
			pq.add(new int[] {smonth, sday, emonth, eday});
		}
		
		int cnt = 0;
		boolean flag = false;
		while(!pq.isEmpty()) {
			int [] flower = pq.poll();
			
			//가장 빨리 피는 꽃도 오늘보다 늦게 핀다면 만족할 수 없음
			if(flower[0] > month || (flower[0] == month && flower[1] > day)){
				break;
			}
			
			int tempM = flower[2];
			int tempD = flower[3];
			
			while(!pq.isEmpty()) {
				int [] next = pq.peek();
				if(next[0] > month || (next[0] == month && next[1] > day)){
					break;
				}
				
				//다음으로 빨리 피는 꽃도 오늘이나 오늘 전에 폈다면
				pq.poll();
				
				//지는 날이 temp보다 늦다면
				if(next[2] > tempM || (next[2] == tempM && next[3] > tempD)) {
					tempM = next[2];
					tempD = next[3];
				}
			}
			
			month = tempM;
			day = tempD;
			cnt++;
			
			if(month == 12) {
				flag = true;
				break;
			}
		}
		
		System.out.println(flag ? cnt : 0);
	}
}

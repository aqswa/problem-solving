package d0216;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj11000 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		int [][] lectures = new int[N][2];
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			lectures[i][0] = Integer.parseInt(st.nextToken());
			lectures[i][1] = Integer.parseInt(st.nextToken());
		}
		
		//강의를 시작 시간 순으로 정렬
		Arrays.sort(lectures, (o1, o2) -> {
			if(o1[0] == o2[0]) {
				return Integer.compare(o1[1], o2[1]);
			}
			return Integer.compare(o1[0], o2[0]);
		});
		
/*
13 46
24 37
35
 * */
		//강의실의 끝나는 시간이 빠른 시간 순 우선순위 큐
		//시작 시간 가장 빠른 강의가 가장 빨리 끝나는 강의실 사용할 수 없다면 다른 모든 강의실 쓸 수 없음. 
		//강의는 어떤 강의실에서라도 진행되어야 하므로 끝나는 시간 관계없이 빨리 시작하는 강의부터 빨리 끝난 강의실에 넣음.
		//새로운 강의실 만들어야 함. 
		int cnt = 0;
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int i=0; i<N; i++) {
			if(!pq.isEmpty() && pq.peek() <= lectures[i][0]) {
				pq.poll();
			}
			else {
				cnt++;
			}
			pq.add(lectures[i][1]);
		}
		
		System.out.println(cnt);
	}
}

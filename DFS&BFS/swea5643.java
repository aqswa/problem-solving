import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class swea5643 {
	
	static int N, M;
	static ArrayList<ArrayList<Integer>> graph;
	static int[] count;
	
	public static void bfs(int start) {
		Queue<Integer> q = new ArrayDeque<>();
		boolean [] visited = new boolean[N+1];
		visited[start] = true;
		q.add(start);
		int cnt = 0; //연결된 진출 정점 수
		while(!q.isEmpty()) {
			int cur = q.poll();
			
			for(int next : graph.get(cur)) {
				if(!visited[next]) {
					visited[next] = true;
					count[next]++;
					cnt++;
					q.add(next);
				}
			}
		}
		
		count[start] += cnt;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(br.readLine()); //학생 수
			M = Integer.parseInt(br.readLine()); //키 관계 수
			
			graph = new ArrayList<ArrayList<Integer>>();
			for(int i=0; i<=N; i++) {
				graph.add(new ArrayList<Integer>());
			}
			
			for(int i=0; i<M; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				
				graph.get(a).add(b); //a가 b보다 작음
			}
			
			count = new int[N+1]; //1~N번 학생까지 진입, 진출하는 노드 수
			for(int i=1; i<=N; i++) {
				bfs(i);
			}
			
			int cnt = 0;
			for(int i=1; i<=N; i++) {
				//System.out.print(count[i] + " ");
				if(count[i] == N-1) {
					cnt++;
				}
			}
			
			sb.append("#" + t + " " + cnt + "\n");
		}

		System.out.println(sb);
	}
}

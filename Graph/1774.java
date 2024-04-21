import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj1774 {
	
	static int N, M; //정점 개수, 이미 연결된 간선 개수
	static int edges[][];
	static double cost[][];
	
	public static double getDistance(int x1, int y1, int x2, int y2) {
		return Math.sqrt(Math.pow(x1-x2, 2) + Math.pow(y1-y2, 2));
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken()); //황선자씨 포함 정점 개수는 N개
		M = Integer.parseInt(st.nextToken());
		edges = new int[N+1][2]; //황선자 씨 포함 1 ~ N개의 정점들의 위치
		cost = new double[N+1][N+1];
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(br.readLine());
			edges[i][0] = Integer.parseInt(st.nextToken());
			edges[i][1] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=i+1; j<=N; j++) {
				cost[i][j] = getDistance(edges[i][0], edges[i][1], edges[j][0], edges[j][1]);
				cost[j][i] = cost[i][j];
			}
		}
		
		for(int i=1; i<=M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			cost[a][b] = cost[b][a] = 0;
		}
		
		System.out.printf("%.2f", prim());
	}
	
	public static double prim() {
		PriorityQueue<double []> pq = new PriorityQueue<>((o1, o2) -> {
			return Double.compare(o1[0], o2[0]);
		});
	    boolean visited[] = new boolean[N+1];
	    pq.add(new double[] {0, 1}); //1번 정점에서 시작
	    
	    double total = 0.0;
	    int cnt = 0;
	    while(!pq.isEmpty()) {
	    	double weight = pq.peek()[0];
	    	int cur = (int) pq.peek()[1];
	    	pq.poll();
	    	
	    	if(visited[cur])
	    		continue;
	    	
	    	visited[cur] = true;
	    	total += weight;
	    	cnt++;
	    	
	    	for(int j=1; j<=N; j++) {
	    		if(!visited[j]) {
	    			pq.add(new double[] {cost[cur][j], j});
	    		}
	    	}
	    	
	    	if(cnt == N) {
	    		break;
	    	}
	    }
	    
	    return total;
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Pair<T> implements Comparable<T>{
	private int x;
	private int y;
	
	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	@Override
	public int compareTo(T o) {
		// TODO Auto-generated method stub
		return this.x - ((Pair) o).getX();
	}
	
}

public class boj2493 {
	
	static int N;
	static int [] heights;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		heights = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			heights[i] = Integer.parseInt(st.nextToken());
		}
		
		int [] receiver = new int [N];
		PriorityQueue<Pair> pq = new PriorityQueue<>(); //탑 높이, 탑 인덱스
		for(int i=N-1; i>=0; i--) {
			while(!pq.isEmpty()) {
				Pair top = pq.peek();
				if(top.getX() <= heights[i]) {
					receiver[top.getY()] = i+1;
					pq.poll();
				}
				else {
					break;
				}
			}
			Pair cur = new Pair(heights[i], i);
			pq.add(cur);
		}
		
		while(!pq.isEmpty()) {
			Pair top = pq.peek();
			receiver[top.getY()] = 0;
			pq.poll();
		}
		
		for(int i=0; i<N; i++) {
			sb.append(receiver[i]).append(" ");
		}
		
		System.out.println(sb);
	}
}

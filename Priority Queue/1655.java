import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class boj1655 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> maxHeap = new PriorityQueue<>((o1, o2) -> {
			return Integer.compare(-o1, -o2);
		}); //최대 힙
		
		PriorityQueue<Integer> minHeap = new PriorityQueue<>((o1, o2) -> {
			return Integer.compare(o1, o2);
		}); //최소 힙
		
		while((N--) != 0) {
			int num = Integer.parseInt(br.readLine());
			
			if(maxHeap.size() > minHeap.size()) {
				minHeap.add(num);
			} else {
				maxHeap.add(num);
			}
			
			if(!maxHeap.isEmpty() && !minHeap.isEmpty() && maxHeap.peek() > minHeap.peek()) {
				int a = maxHeap.poll();
				int b = minHeap.poll();
				
				maxHeap.add(b);
				minHeap.add(a);
			}
			
			sb.append(maxHeap.peek() + "\n");
		}
		
		System.out.println(sb);
	}
}

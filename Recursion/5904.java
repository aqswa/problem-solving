import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj5904 {
	
	static int N;
	static int[] arr;
	
	public static void recur(int n) {
		
		int idx = 0;
		for(int i=1; i<arr.length; i++) {
			if(arr[i] < n) {
				idx++;
			}
			else {
				break;
			}
		}
		
		if(n == arr[idx] + 1) {
			System.out.println("m");
			return;
		}
		else if(n >= (arr[idx]+2) && n <= (arr[idx]+idx+3)) {
			System.out.println("o");
			return;
		}
		else {
			recur(n - (arr[idx] + idx+3));
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		arr = new int [30];
		arr[0] = 0;
		int idx = 0;
		while(true) {
			if(N > arr[idx]) {
				arr[idx+1] = arr[idx] * 2 + (idx + 3);
				idx++;
			}
			else {
				break;
			}
		}
		
		recur(N);
	}
}

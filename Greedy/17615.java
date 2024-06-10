import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj17615 {
	
	static int N;
	static char[] s;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		s = br.readLine().toCharArray();
		
		//R을 옮기는 경우
		int moveR = 0;
		int idx = N-1;
		while(idx >= 0 && s[idx] == 'R') {
			idx--;
		}
		
		for(int i=idx; i>=0; i--) {
			if(s[i] == 'R') {
				moveR++;
			}
		}
		
		idx = 0;
		int moveRL = 0;
		while(idx < N && s[idx] == 'R') {
			idx++;
		}
		
		for(int i=idx; i<N; i++) {
			if(s[i] == 'R') {
				moveRL++;
			}
		}
		
		moveR = moveR > moveRL ? moveRL : moveR;
		
		//B를 옮기는 경우
		int moveB = 0;
		idx = N-1;
		while(idx >= 0 && s[idx] == 'B') {
			idx--;
		}
		
		for(int i=idx; i>=0; i--) {
			if(s[i] == 'B') {
				moveB++;
			}
		}
		
		int moveBL = 0;
		idx = 0;
		while(idx < N && s[idx] == 'B') {
			idx++;
		}
		
		for(int i=idx; i<N; i++) {
			if(s[i] == 'B') {
				moveBL++;
			}
		}
		
		moveB = moveB > moveBL ? moveBL : moveB;
		
		System.out.println(moveR > moveB ? moveB : moveR);
		
		/*
		 * 
		for(int i = 0; i < str.length; i++) {
			if(str[i] == 'R') redMax++;
			else blueMax++;
		}
		answer = Math.min(redMax, blueMax);
		
		for(int i = 0; i < str.length; i++) {
			if(str[0] != str[i]) break;
			cnt++;
		}
		
		if(str[0] == 'R') answer = Math.min(answer, redMax - cnt);
		else answer = Math.min(answer, blueMax - cnt);
		
		cnt = 0;
		for(int i = length - 1; i >= 0; i--) {
			if(str[length - 1] != str[i]) break;
			cnt++;
		}
		
		if(str[length - 1] == 'R') answer = Math.min(answer, redMax - cnt);
		else answer = Math.min(answer, blueMax - cnt);
		
		System.out.println(answer);*/
	}
}

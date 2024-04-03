import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea4013{
	static int [][] wheels = new int[4][8];
	static int [] head;
	
	public static void rotate(int idx, int dir) {
		if (dir == 1) { //시계 방향
			head[idx] = (head[idx] + 7) % 8;
		}
		else {
			head[idx] = (head[idx] + 1) % 8;
		}
	}

	public static int calc_score() { //0이면 0점, 1이면 1점
		int total = 0;
		for (int i = 0; i < 4; i++) {
			total += wheels[i][head[i]] * Math.pow(2, i);
		}
		return total;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for (int t = 1; t <= T; t++) {
			int K = Integer.parseInt(br.readLine());
			head = new int[4];

			//톱니바퀴 자성 입력
			for (int i = 0; i < 4; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 8; j++) {
					wheels[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			for (int i = 0; i < K; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int idx = Integer.parseInt(st.nextToken()); //회전 시작할 톱니 인덱스
				int dir = Integer.parseInt(st.nextToken()); //회전 방향
				
				idx = idx - 1;
			    int temp_dir = dir;

	            //오른쪽 톱니바퀴들
	            for(int k=idx; k<4; k++) {
	                if(k != 3) { //마지막 톱니바퀴 아니라면
	                    int a = (head[k] + 2) % 8; //현재 톱니의 오른쪽 끝 인덱스
	                    int b = (head[k+1] + 6) % 8; //오른쪽 톱니의 왼쪽 끝 인덱스
	                    if(wheels[k][a] != wheels[k+1][b]) { //자성이 다르면 다음 회전할 방향 바꿈
	                        rotate(k, temp_dir);
	                        temp_dir *= -1;
	                    }
	                    else { //자성 같으면 회전 끝
	                        rotate(k, temp_dir);
	                        break;
	                    }
	                } else {
	                    rotate(k, temp_dir);
	                }
	            }
	            
	            rotate(idx, dir * -1);
	            
	            //왼쪽 톱니바퀴들
	            for(int k=idx; k>=0; k--) {
	            	if(k != 0) {
	                    int a = (head[k] + 6) % 8; //현재 톱니의 왼쪽 끝 인덱스
	                    int b = (head[k-1] + 2) % 8; //왼쪽 톱니의 오른쪽 끝 인덱스
	                    
	                    if(wheels[k][a] != wheels[k-1][b]) { //자성이 다르다면
	                        rotate(k, dir);
	                        dir *= -1;
	                    } else {
	                        rotate(k, dir);
	                        break;
	                    }
	            	} else {
	            		rotate(k, dir);
	            	}
	            }
	            
			}

			int ans = calc_score();
			sb.append("#" + t + " " + ans + "\n");
		}
		
		System.out.println(sb);
	}
}

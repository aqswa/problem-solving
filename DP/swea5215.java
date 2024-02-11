import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {

    static int N, L;
    static int ingred[][];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for(int t=1; t<=T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken()); //재료 개수
            L = Integer.parseInt(st.nextToken()); //칼로리 제한

            ingred = new int[N][2];
            for(int i=0; i<N; i++) {
                st = new StringTokenizer(br.readLine());
                ingred[i][0] = Integer.parseInt(st.nextToken()); //점수
                ingred[i][1] = Integer.parseInt(st.nextToken()); //칼로리
            }

            //증가하면서 검사할 때 1차원 DP를 사용하면 물품을 중복으로 사용하는 경우가 생길 수 있어서 2차원 배열을 사용해 물품 분리
            //감소하면서 검사하면 중복 방지되어 1차원 배열 사용 가능하다
            int dp[] = new int[L+1];
            Arrays.fill(dp, 0);
            for(int i=0; i<N; i++){
                for(int j=L; j>ingred[i][1]; j--){
                    dp[j] = Math.max(dp[j-ingred[i][1]] + ingred[i][0], dp[j]);
                }
            }

            sb.append("#").append(t).append(" ").append(dp[L]).append("\n");
        }

        System.out.println(sb);
    }
}

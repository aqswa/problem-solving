import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
 
public class Solution {
    static int N;
    static int islands[][];
    static double cost[][];
    static double E;
     
    public static double getCost(int x1, int y1, int x2, int y2) {
        return E * (Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
    }
     
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
 
        int T = Integer.parseInt(br.readLine());
         
        for(int t=1; t<=T; t++) {
            N = Integer.parseInt(br.readLine());
            islands = new int [N][2];
            cost = new double[N][N];
            for(int i=0; i<2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j=0; j<N; j++) {
                    islands[j][i] = Integer.parseInt(st.nextToken());
                }
            }
             
            E = Double.parseDouble(br.readLine());
            for(int i=0; i<N; i++) {
                for(int j=i+1; j<N; j++) {
                    cost[i][j] = getCost(islands[i][0], islands[i][1], islands[j][0], islands[j][1]);
                    cost[j][i] = cost[i][j];
                }
            }
             
            sb.append("#").append(t).append(" ").append(String.format("%.0f", prim())).append("\n");
        }
         
        System.out.println(sb);
    }
     
    public static double prim() {
        PriorityQueue<double []> pq = new PriorityQueue<double[]>((o1, o2) -> {
            return Double.compare(o1[0], o2[0]);
        });
        boolean visited[] = new boolean[N];
        double total = 0;
        int cnt = 0;
        pq.add(new double[] {0, 0}); //정점까지의 가중치, 정점 번호
         
        while(!pq.isEmpty()) {
            int cur = (int)pq.peek()[1];
            double weight = pq.peek()[0];
            pq.poll();
             
            if(visited[cur])
                continue;
             
            total += weight;
            cnt++;
            visited[cur] = true;
             
            for(int i=0; i<N; i++) {
                if(!visited[i]) {
                    pq.add(new double[] {cost[cur][i], i});
                }
            }
             
            if(cnt == N)
                break;
        }
         
        //return total;
        return Math.round(total);
    }
}

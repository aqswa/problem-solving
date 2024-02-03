package hello.core;

import java.io.*;
import java.math.BigInteger;

public class boj1914 {

    public static int N;
    public static int cnt;
    public static StringBuilder sb = new StringBuilder();

    public static void hanoi(int n, int from, int mid, int to) {
        if(n == 0)
            return;

        hanoi(n-1, from, to, mid);
        sb.append(from).append(" ").append(to).append('\n');
        hanoi(n-1, mid, from, to);
    }

    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        BigInteger cnt = new BigInteger("2");
        System.out.println(cnt.pow(N).subtract(new BigInteger("1")));

        if(N < 21) {
            hanoi(N, 1, 2, 3);
            System.out.println(sb);
        }
    }

}

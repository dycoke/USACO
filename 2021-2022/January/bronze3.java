import java.io.*;
import java.util.*;

public class bronze3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int t = Integer.parseInt(br.readLine());
        for (int z = 0; z < t; z++) {
            long ans = 0;
            int n = Integer.parseInt(br.readLine());
            boolean works = true;
            long[] cows = new long[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                cows[i] = Long.parseLong(st.nextToken());
            }
            if (n == 1) {
                pw.println(0);
                continue;
            } else if (n == 2) {
                if (cows[0] != cows[1]) {
                    works = false;
                }
            } else {
                works = false;
                while (!works) {
                    if (cows[0] > cows[1] || cows[n - 1] > cows[n - 2]) {
                        works = false;
                        break;
                    }
                    works = true;
                    int index = 0;
                    long max = Long.MIN_VALUE;
                    long temp = cows[0];
                    for (int i = 0; i < n; i++) {
                        if (cows[i] != temp) {
                            works = false;
                        } if (cows[i] > max && i > 0 && i < n - 1) {
                            max = cows[i];
                            index = i;
                        }
                    }
                    while (index < n - 1 && cows[index - 1] == cows[index] && cows[index + 1] == cows[index]) {
                        index++;
                    }
                    if (works) {
                        break;
                    }
                    long tem;
                    if (cows[index - 1] >= cows[index + 1]) {
                        tem = cows[index] - cows[index + 1];
                        cows[index - 1] -= tem;
                        cows[index] = cows[index + 1];
                        if (cows[index - 1] < 0) {
                            works = false;
                            break;
                        }
                    } else {
                        tem = cows[index] - cows[index - 1];
                        cows[index + 1] -= tem;
                        cows[index] = cows[index - 1];
                        if (cows[index + 1] < 0) {
                            works = false;
                            break;
                        }
                    }
                    ans += tem;
                }
            }
            long temp = cows[0];
            for (int i = 0; i < n; i++) {
                if (cows[i] != temp) {
                    works = false;
                    break;
                }
            }
            if (works) {
                pw.println(ans * 2);
            } else {
                pw.println(-1);
            }
        }
        pw.close();
        br.close();
    }
}

/*
more java solutions
bronze was actually goated
brute force >
*/
import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("outofplace.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("outofplace.out")));
        int n = Integer.parseInt(br.readLine());
        int[] lineup = new int[n];
        int[] sorted = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int temp = Integer.parseInt(br.readLine());
            lineup[i] = temp;
            sorted[i] = temp;
        }
        Arrays.sort(sorted);
        for (int i = n - 1; i >= 0; i--) {
            if (sorted[i] != lineup[i]) {
                for (int j = 0; j < n; j++) {
                    if (lineup[j] == sorted[i]) {
                        int temp = lineup[j];
                        lineup[j] = lineup[i];
                        lineup[i] = temp;
                        ans++;
                        break;
                    }
                }
            }
        }
        pw.println(ans);
        pw.close();
        br.close();
    }
}

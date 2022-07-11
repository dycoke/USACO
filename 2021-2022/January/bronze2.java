import java.io.*;
import java.util.*;

public class bronze2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] die1 = new int[4];
            int[] die2 = new int[4];
            int[] die3 = new int[4];
            boolean works = false;
            for (int j = 0; j < 4; j++) {
                die1[j] = Integer.parseInt(st.nextToken());
            }
            for (int j = 0; j < 4; j++) {
                die2[j] = Integer.parseInt(st.nextToken());
            }
            int t = win(die1, die2);
            if (t == 0) {
                pw.println("no");
                continue;
            }
            for (int p1 = 0; p1 < 10; p1++) {
                if (works) {
                    break;
                }
                for (int p2 = 0; p2 < 10; p2++) {
                    if (works) {
                        break;
                    }
                    for (int p3 = 0; p3 < 10; p3++) {
                        if (works) {
                            break;
                        }
                        for (int p4 = 0; p4 < 10; p4++) {
                            die3[0] = p1 + 1;
                            die3[1] = p2 + 1;
                            die3[2] = p3 + 1;
                            die3[3] = p4 + 1;
                            boolean c = win(die3, die1) == t;
                            boolean b = win(die2, die3) == t;
                            if (b && c) {
                                pw.println("yes");
                                works = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (!works) {
                pw.println("no");
            }
        }
        pw.close();
        br.close();
    }

    public static int win(int[] a, int[] b) {
        int aw = 0;
        int bw = 0;
        for (int k : a) {
            for (int i : b) {
                if (k != i) {
                    if (k > i) {
                        aw++;
                    } else {
                        bw++;
                    }
                }
            }
        }
        if (aw > bw) {
            return 1;
        } else if (bw > aw) {
            return 2;
        }
        return 0;
    }
}

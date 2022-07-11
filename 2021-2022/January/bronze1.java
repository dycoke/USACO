import java.io.*;
import java.util.*;
public class bronze1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int ans1 = 0;
        int ans2 = 0;
        char[][] correct = new char[3][3];
        char[][] guess = new char[3][3];
        HashMap<Character, Integer> cor = new HashMap<>();
        HashMap<Character, Integer> gue = new HashMap<>();
        HashMap<Character, Integer> corr = new HashMap<>();
        for (int i = 0; i < 3; i++) {
            String temp = br.readLine();
            correct[i] = temp.toCharArray();
            for (int j = 0; j < 3; j++) {
                if (cor.containsKey(correct[i][j])) {
                    cor.put(correct[i][j], cor.get(correct[i][j]) + 1);
                } else {
                    cor.put(correct[i][j], 1);
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            String temp = br.readLine();
            guess[i] = temp.toCharArray();
            for (int j = 0; j < 3; j++) {
                if (gue.containsKey(guess[i][j])) {
                    gue.put(guess[i][j], gue.get(guess[i][j]) + 1);
                } else {
                    gue.put(guess[i][j], 1);
                }
            }
        }
        for (int x1 = 0; x1 < 3; x1++) {
            for (int y1 = 0; y1 < 3; y1++) {
                for (int x2 = 0; x2 < 3; x2++) {
                    for (int y2 = 0; y2 < 3; y2++) {
                        boolean temp = correct[x1][y1] == guess[x2][y2] && x1 == x2;
                        if (temp && y1 == y2) {
                            if (corr.containsKey(correct[x1][y1])) {
                                corr.put(correct[x1][y1], corr.get(correct[x1][y1]) + 1);
                            } else {
                                corr.put(correct[x1][y1], 1);
                            }
                        }
                    }
                }
            }
        }
        for (Character i : cor.keySet()) {
            if (gue.containsKey(i)) {
                if (corr.containsKey(i)) {
                    int temp = Math.min(gue.get(i), cor.get(i)) - corr.get(i);
                    if (temp >= 0) {
                        ans2 += temp;
                    } else {
                        ans2 += gue.get(i);
                    }
                }
                else
                {
                    int temp = Math.min(gue.get(i), cor.get(i));
                    ans2 += temp;
                }
            }
        }
        for (Character i : corr.keySet()) {
            ans1 += corr.get(i);
        }
        pw.println(ans1);
        pw.println(ans2);
        br.close();
        pw.close();
    }
}

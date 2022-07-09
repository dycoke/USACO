import java.io.*;
import java.util.*;
public class bronze3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("measurement.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));
        int n = Integer.parseInt(br.readLine());
        int ans = 0;
        log[] milkLog = new log[n];
        HashMap<String, Integer> logicTable = new HashMap<>();
        logicTable.put("Bessie", 0);
        logicTable.put("Elsie", 1);
        logicTable.put("Mildred", 2);
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            int name = logicTable.get(st.nextToken());
            String amount = st.nextToken();
            int amt = 0;
            if (amount.substring(0, 1).equals("+")) {
                amt = Integer.parseInt(amount.substring(1));
            } else {
                amt = - Integer.parseInt(amount.substring(1));
            }
            log temp = new log(time, name, amt);
            milkLog[i] = temp;
        }
        cow[] cows = new cow[3];
        makeCow(cows);
        Arrays.sort(milkLog);
        String previous = "";
        int previousTie = 0;
        for (int i = 0; i < n; i++) {
            cows[milkLog[i].cow].amount += milkLog[i].amount;
            cow[] copy = Arrays.copyOf(cows, cows.length);
            Arrays.sort(copy);
            int tied = numTie(copy);
            if (!copy[2].name.equals(previous) || tied != previousTie) {
                ans++;
                previous = copy[2].name;
                previousTie = tied;
            }
        }
        pw.println(ans);
        pw.close();
        br.close();
    }
    public static void makeCow(cow[] cows) {
        cow Bessie = new cow("Bessie", 7);
        cows[0] = Bessie;
        cow Elsie = new cow("Elsie", 7);
        cows[1] = Elsie;
        cow Mildred = new cow("Mildred", 7);
        cows[2] = Mildred;

    }
    public static int numTie(cow[] cows) {
        int ans = 0;
        int previous = cows[2].amount;
        for(int i = cows.length - 1; i >= 0; i--) {
            if (cows[i].amount == previous) {
                ans++;
            } else {
                return ans;
            }
        }
        return ans;
    }
}
class log implements Comparable<log> {
    public int time;
    public int cow;
    public int amount;
    public log(int t, int c, int a) {
        time = t;
        cow = c;
        amount = a;
    }
    public int compareTo(log other) {
        return time - other.time;
    }
}
class cow implements Comparable<cow> {
    public String name;
    public int amount;

    public cow(String n, int a) {
        name = n;
        amount = a;
    }

    public int compareTo(cow other) {
        return amount - other.amount;
    }
}

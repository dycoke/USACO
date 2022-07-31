import java.io.*;
import java.util.*;
public class bronze3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("measurement.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));
        int n = Integer.parseInt(br.readLine());
        int ans = 0;
        Log[] milkLog = new Log[n];
        HashMap<String, Integer> LogicTable = new HashMap<>();
        LogicTable.put("Bessie", 0);
        LogicTable.put("Elsie", 1);
        LogicTable.put("Mildred", 2);
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            int name = LogicTable.get(st.nextToken());
            String amount = st.nextToken();
            int amt = 0;
            if (amount.substring(0, 1).equals("+")) {
                amt = Integer.parseInt(amount.substring(1));
            } else {
                amt = -Integer.parseInt(amount.substring(1));
            }
            Log temp = new Log(time, name, amt);
            milkLog[i] = temp;
        }
        Cow[] Cows = new Cow[3];
        makeCow(Cows);
        Arrays.sort(milkLog);
        String previous = "";
        int previousTie = 0;
        for (int i = 0; i < n; i++) {
            Cows[milkLog[i].cow].amount += milkLog[i].amount;
            Cow[] copy = Arrays.copyOf(Cows, Cows.length);
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
    public static void makeCow(Cow[] Cows) {
        Cow Bessie = new Cow("Bessie", 7);
        Cows[0] = Bessie;
        Cow Elsie = new Cow("Elsie", 7);
        Cows[1] = Elsie;
        Cow Mildred = new Cow("Mildred", 7);
        Cows[2] = Mildred;

    }
    public static int numTie(Cow[] Cows) {
        int ans = 0;
        int previous = Cows[2].amount;
        for(int i = Cows.length - 1; i >= 0; i--) {
            if (Cows[i].amount == previous) {
                ans++;
            } else {
                return ans;
            }
        }
        return ans;
    }
}
class Log implements Comparable<Log> {
    public int time;
    public int cow;
    public int amount;
    public Log(int t, int c, int a) {
        time = t;
        cow = c;
        amount = a;
    }
    public int compareTo(Log other) {
        return time - other.time;
    }
}
class Cow implements Comparable<Cow> {
    public String name;
    public int amount;

    public Cow(String n, int a) {
        name = n;
        amount = a;
    }

    public int compareTo(Cow other) {
        return amount - other.amount;
    }
}

//the old java days...
//fastest java tc is slower than slowest c++ tc lmao
import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("citystate.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("citystate.out")));
        HashMap<String, Integer> cities = new HashMap<>();
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String city = st.nextToken().substring(0, 2);
            String state = st.nextToken();
            if (!cities.containsKey(city + state)) {
                cities.put(city + state, 1);
            } else {
                cities.put(city + state, cities.get(city + state) + 1);
            }
        }
        int ans = 0;
        for (String current : cities.keySet()) {
            if (cities.get(current.substring(2) + current.substring(0, 2)) != null && !(current.substring(2, 4).equals(current.substring(0, 2)))) {
                ans = ans + (cities.get(current) * cities.get(current.substring(2) + current.substring(0, 2)));
            }
        }
        pw.println(ans / 2);
        pw.close();
        br.close();
    }
}

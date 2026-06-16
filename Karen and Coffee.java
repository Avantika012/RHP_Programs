//Karen and Coffee
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int q = sc.nextInt();

        int MAX = 200000;

        int[] diff = new int[MAX + 2];
        int[] pref = new int[MAX + 2];

        for (int i = 0; i < n; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();

            diff[l]++;
            diff[r + 1]--;
        }

        int active = 0;

        for (int i = 1; i <= MAX; i++) {
            active += diff[i];

            pref[i] = pref[i - 1];
            if (active >= k) {
                pref[i]++;
            }
        }

        while (q-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            System.out.println(pref[b] - pref[a - 1]);
        }
    }
}
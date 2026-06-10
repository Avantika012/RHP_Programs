// To find the length of the Longest Common Subsequence between two strings

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s1 = sc.next();
        String s2 = sc.next();

        int a = s1.length();
        int b = s2.length();

        int[][] dp = new int[b + 1][a + 1];

        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= a; j++) {
                if (s2.charAt(i - 1) == s1.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    if (dp[i - 1][j] > dp[i][j - 1]) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }

        System.out.println(dp[b][a]);
    }
}
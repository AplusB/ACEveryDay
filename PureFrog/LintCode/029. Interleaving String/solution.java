/*
 * dp[i][j]，第一个匹配到i第二个匹配到j匹配的第三个长度。
 */
import java.lang.Math;

public class Solution {
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true or false.
     */
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1 == null && s2 == null && s3 == null)
            return true;
        if (s3.length() == 0 && s1.length() == 0 && s2.length() == 0)
            return true;
        if (s1 == null || s2 == null || s3 == null || s3.length() != s1.length() + s2.length())
            return false;

        int[][] dp = new int[s1.length() + 2][s2.length() + 2];

        for (int i = 0; i <= s1.length(); ++i) {
            for (int j = 0; j <= s2.length(); ++j) {
                int pos = dp[i][j];
                if (i != s1.length() && s1.charAt(i) == s3.charAt(pos))
                    dp[i + 1][j] = Math.max(dp[i + 1][j], pos + 1);
                if (j != s2.length() && s2.charAt(j) == s3.charAt(pos))
                    dp[i][j + 1] = Math.max(dp[i][j + 1], pos + 1);
            }
        }
        return dp[s1.length()][s2.length()] == s3.length();
    }
}

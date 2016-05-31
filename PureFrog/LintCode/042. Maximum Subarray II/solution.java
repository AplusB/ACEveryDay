public class Solution {
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    public int maxTwoSubArrays(ArrayList<Integer> nums) {
        if (nums == null)
            return 0;

        int n = nums.size();
        int k = 2;
        int[][][] dp = new int[n + 1][k + 1][2];

        for (int i = 0; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
                for (int kk = 0; kk < 2; ++kk)
                    dp[i][j][kk] = Integer.MIN_VALUE;
        
        for (int i = 1; i <= n; ++i) {
            int currentNum = nums.get(i - 1);
            for (int j = 1; j <= Math.min(i, k); ++j) {
                //当前数不选
                dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1]);
                //接上旧的
                if (dp[i - 1][j][1] != Integer.MIN_VALUE)
                    dp[i][j][1] = dp[i - 1][j][1] + currentNum;
                //重新起一段
                if (i != 1) 
                    dp[i][j][1] = Math.max(dp[i][j][1], Math.max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + currentNum);
                else
                    dp[i][j][1] = currentNum;
            }
        }
        return Math.max(dp[n][k][0], dp[n][k][1]);
    }
}



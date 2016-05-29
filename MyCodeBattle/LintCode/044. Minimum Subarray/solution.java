public class Solution {
    /**
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    public int minSubArray(ArrayList<Integer> nums) {
        if (nums == null)
            return 0;
        int[] dp = new int[nums.size() + 1];

        int ans = Integer.MAX_VALUE;
        dp[0] = Integer.MAX_VALUE;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i + 1] = Math.min(0, dp[i]) + nums.get(i);
            ans = Math.min(ans, dp[i + 1]);
        }
        return ans;

    }
}


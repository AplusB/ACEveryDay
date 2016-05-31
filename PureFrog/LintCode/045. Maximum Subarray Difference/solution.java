public class Solution {
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    public int maxDiffSubArrays(int[] nums) {
        if (nums.length == 0)
            return 0;

        int[] leftMin = new int[nums.length + 10];
        int[] leftMax = new int[nums.length + 10];
        int[] rightMax = new int[nums.length + 10];
        int[] rightMin = new int[nums.length + 10];

        int curMax = 0;
        int curMin = 0;
        int sum = 0;

        leftMin[0] = Integer.MAX_VALUE;
        leftMax[0] = Integer.MIN_VALUE;
        for (int i = 1; i <= nums.length; ++i) {
            sum += nums[i - 1];
            leftMin[i] = Math.min(leftMin[i - 1], sum - curMax);
            leftMax[i] = Math.max(leftMax[i - 1], sum - curMin);
            curMax = Math.max(curMax, sum);
            curMin = Math.min(curMin, sum);
        }

        int ans = 0;
        curMax = 0;
        curMin = 0;
        rightMax[nums.length + 1] = Integer.MIN_VALUE;
        rightMin[nums.length + 1] = Integer.MAX_VALUE;

        sum = 0;
        for (int i = nums.length; i > 1; --i) {
            sum += nums[i - 1];
            rightMax[i] = Math.max(rightMax[i + 1], sum - curMin);
            rightMin[i] = Math.min(rightMin[i + 1], sum - curMax);
            curMin = Math.min(curMin, sum);
            curMax = Math.max(curMax, sum);
            ans = Math.max(ans, Math.abs(rightMax[i] - leftMin[i - 1]));
            ans = Math.max(ans, Math.abs(rightMin[i] - leftMax[i - 1]));
        }
        return ans;
    }
}



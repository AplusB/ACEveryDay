public class Solution {
	/** 
     *@param nums: The integer array you should partition
     *@param k: As description
     *return: The index after partition
     */

    private void swap(int[] nums, int l, int r) {
        int temp = nums[r];
        nums[r] = nums[l];
        nums[l] = temp;
    }

    public int partitionArray(int[] nums, int k) {
        if (nums.length == 0)
            return 0;
        int l = 0, r = nums.length - 1;
        for (int i = 0; i < nums.length && i <= r; ++i) {
            int u = nums[i];
            if (nums[i] < k) {
                swap(nums, i, l++);
            }
            else if (nums[i] > k) {
                swap(nums, i, r--);
                --i;
            }
        }
        return l;
    }
    
}


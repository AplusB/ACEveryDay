/*
 * 堆和快排思想都可以，不知道用堆会不会超时。
 */
import java.lang.Math;

class Solution {
    /*
     * @param k : description of k
     * @param nums : array of nums
     * @return: description of return
     */

    int partition(int[] nums, int l, int r, int k) {

        if (l == r)
            return nums[l];
        int idx = l + (int) (Math.random() * (r - l));
        int pivot = nums[idx];
        int temp = nums[r];
        nums[r] = nums[idx];
        nums[idx] = temp;

        int pos = l;
        for (int i = l; i < r; ++i) {
            if (nums[i] <= pivot) {
                temp = nums[i];
                nums[i] = nums[pos];
                nums[pos++] = temp;
            }
        }

        temp = nums[pos];
        nums[pos++] = nums[r];
        nums[r] = temp;
        if (pos - l >= k)
            return partition(nums, l, pos - 1, k);
        else
            return partition(nums, pos, r, k - (pos - l));

    }

    public int kthLargestElement(int k, int[] nums) {
        // write your code here
        int n = nums.length;
        k = n - k + 1;
        return partition(nums, 0, nums.length - 1, k);
    }
};


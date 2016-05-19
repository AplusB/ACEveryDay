public class Solution {
    /**
     * @param nums: The rotated sorted array
     * @return: void
     */

    private void swap(ArrayList<Integer> nums, int l, int r) {
        if (l >= r)
            return;
        while (l < r) {
            int temp = nums.get(l);
            nums.set(l, nums.get(r));
            nums.set(r, temp);
            ++l; --r;
        }
    }

    public void recoverRotatedSortedArray(ArrayList<Integer> nums) {
        if (nums == null || nums.size() == 1)
            return;

        int index = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums.get(i) < nums.get(i - 1)) {
                index = i;
                break;
            }
        }
        swap(nums, 0, index - 1);
        swap(nums, index, nums.size() - 1);
        swap(nums, 0, nums.size() - 1);
    }
}

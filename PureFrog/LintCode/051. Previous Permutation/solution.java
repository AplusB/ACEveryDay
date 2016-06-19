public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */

    private void reverse(int begin, ArrayList<Integer> nums) {
        int r = nums.size() - 1;
        while (begin < r) {
            int temp = nums.get(begin);
            nums.set(begin, nums.get(r));
            nums.set(r, temp);
            --r; ++begin;
        }
    }

    public ArrayList<Integer> previousPermuation(ArrayList<Integer> nums) {
        if (nums == null || nums.size() <= 1)
            return nums;

        int pos = nums.size() - 2;
        while (pos != -1 && nums.get(pos) <= nums.get(pos + 1)) {
            --pos;
        }
        if (pos == -1) {
            reverse(0, nums);
            return nums;
        }

        int swapPos = pos;
        reverse(swapPos + 1, nums);
        for (int i = swapPos + 1; i < nums.size(); ++i) if (nums.get(i) < nums.get(swapPos)) {
            int temp = nums.get(swapPos);
            nums.set(swapPos, nums.get(i));
            nums.set(i, temp);
            break;
        }
        return nums;

    }
}


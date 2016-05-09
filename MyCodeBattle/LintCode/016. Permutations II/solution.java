class Solution {
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    
    private void reverse(int l, int r, ArrayList<Integer> ans) {
        while (l < r) {
            int temp = ans.get(l);
            ans.set(l, ans.get(r));
            ans.set(r, temp);
            ++l; --r;
        }
    }

    private boolean nextPermutation(ArrayList<Integer> nums) {
        int i = nums.size() - 1;
        while (i != 0 && nums.get(i - 1) >= nums.get(i)) {
            --i;
        }
        if (i == 0)
            return false;

        int swapPos = i - 1;
        while (i < nums.size() && nums.get(i) > nums.get(swapPos))
            ++i;

        int temp = nums.get(i - 1);
        nums.set(i - 1, nums.get(swapPos));
        nums.set(swapPos, temp);

        reverse(swapPos + 1, nums.size() - 1, nums);
        return true;
    }

    public ArrayList<ArrayList<Integer>> permuteUnique(ArrayList<Integer> nums) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        if (nums == null)
            return ans;
        Collections.sort(nums);

        do {
            ans.add((ArrayList) nums.clone());
        } while (nextPermutation(nums));

        return ans;
    }
}



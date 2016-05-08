/*
 * 当前一个数字相同并且没选的时候，轮不到自己选。
 */
class Solution {
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
    boolean[] visited;

    private void dfs(int pos, ArrayList<Integer> lis, int[] nums) {
        if (pos == nums.length) {
            ans.add((ArrayList) lis.clone());
            return;
        }

        if (pos == 0 || nums[pos] != nums[pos - 1] || visited[pos - 1]) {
            visited[pos] = true;
            lis.add(nums[pos]);
            dfs(pos + 1, lis, nums);
            visited[pos] = false;
            lis.remove(lis.size() - 1);
        }
        dfs(pos + 1, lis, nums);
    }

    public ArrayList<ArrayList<Integer>> subsets(int[] nums) {
        if (nums.length == 0)
            return ans;
        Arrays.sort(nums);
        visited = new boolean[nums.length];

        dfs(0, new ArrayList<Integer>(), nums);
        return ans;
    }
}

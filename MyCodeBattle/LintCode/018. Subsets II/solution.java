class Solution {
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
    boolean[] visited;

    private void dfs(int pos, ArrayList<Integer> lis, ArrayList<Integer> nums) {
        if (pos == nums.size()) {
            ans.add((ArrayList) lis.clone());
            return;
        }

        if (pos == 0 || nums.get(pos) != nums.get(pos - 1) || visited[pos - 1]) {
            visited[pos] = true;
            lis.add(nums.get(pos));
            dfs(pos + 1, lis, nums);
            visited[pos] = false;
            lis.remove(lis.size() - 1);
        }
        dfs(pos + 1, lis, nums);
    }

    public ArrayList<ArrayList<Integer>> subsetsWithDup(ArrayList<Integer> nums) {
        if (nums.size() == 0)
            return ans;
        Collections.sort(nums);
        visited = new boolean[nums.size()];

        dfs(0, new ArrayList<Integer>(), nums);
        return ans;
    }
}


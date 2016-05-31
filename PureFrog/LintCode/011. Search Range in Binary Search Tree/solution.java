/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    ArrayList<Integer> ans = new ArrayList<>();

    public ArrayList<Integer> searchRange(TreeNode root, int k1, int k2) {
        // write your code here
        if (root == null)
            return ans;
        if (root.val >= k1 && root.val <= k2) {
            searchRange(root.left, k1, k2);
            ans.add(root.val);
            searchRange(root.right, k1, k2);
        }
        else if (root.val < k1) {
            searchRange(root.right, k1, k2);
        }
        else {
            searchRange(root.left, k1, k2);
        }
        return ans;
    }
}

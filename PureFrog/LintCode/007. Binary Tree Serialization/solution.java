/*
 * 模拟前序遍历。
 */

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
class Solution {
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    private StringBuilder sb = new StringBuilder();
    private int pos = 0;

    private void dfs(TreeNode rt) {
        if (rt == null) {
            sb.append("#,");
            return;
        }
        sb.append(rt.val + ",");
        dfs(rt.left);
        dfs(rt.right);
    }

    public String serialize(TreeNode root) {
        if (root == null) {
            return "#";
        }
        dfs(root);
        return sb.toString();
    }
    
    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    public TreeNode deserialize(String data) {
        // write your code here
        if (data.charAt(pos) == '#') {
            pos += 2;
            return null;
        }
        int limitPos = data.indexOf(",", pos);
        TreeNode root = new TreeNode(new Integer(data.substring(pos, limitPos)));
        pos = limitPos + 1;
        root.left = deserialize(data);
        root.right = deserialize(data);
        return root;
    }

}


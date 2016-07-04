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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */

    private TreeNode removeInternalNode(TreeNode curNode) {
        if (curNode.left != null) {
            TreeNode leftMaxNode = curNode.left;

            while (leftMaxNode.right != null && leftMaxNode.right.right != null)
                leftMaxNode = leftMaxNode.right;
            if (leftMaxNode.right == null) {    //叶子结点
                leftMaxNode.right = curNode.right;
                return leftMaxNode;
            }
            else {
                TreeNode selectedNode = leftMaxNode.right;
                leftMaxNode.right = selectedNode.left;
                selectedNode.right = curNode.right;
                selectedNode.left = curNode.left;
                return selectedNode;
            }
        }
        else {
            return curNode.right;
        }
    }

    private TreeNode removeInternal(TreeNode curNode, int value) {
        if (curNode == null)
            return null;
        if (value == curNode.val)
            return removeInternalNode(curNode);
        else if (value > curNode.val)
            curNode.right = removeInternal(curNode.right, value);
        else
            curNode.left = removeInternal(curNode.left, value);
        return curNode;
    }
     
    public TreeNode removeNode(TreeNode root, int value) {
        if (root == null)
            return root;

        return removeInternal(root, value);
    }
}

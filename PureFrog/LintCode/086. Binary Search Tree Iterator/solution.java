/*
 * O(h) 的复杂度。O(1)的怎么搞？？
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
 * Example of iterate a tree:
 * BSTIterator iterator = new BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode node = iterator.next();
 *    do something for node
 * } 
 */
public class BSTIterator {
    //@param root: The root of binary tree.

    TreeNode currentNode;
    Stack<TreeNode> nodes = new Stack<>();

    public BSTIterator(TreeNode root) {
        currentNode = root;
        if (currentNode == null)
            return;
        while (currentNode.left != null) {
            nodes.push(currentNode);
            currentNode = currentNode.left;
        }
    }

    //@return: True if there has next node, or false
    public boolean hasNext() {
        return currentNode != null;
    }
    
    //@return: return next node
    public TreeNode next() {
        TreeNode ret = currentNode;
        if (currentNode.right != null) {
            currentNode = currentNode.right;
        }
        else {
            currentNode = nodes.isEmpty() ? null : nodes.pop();
            return ret;
        }
        while (currentNode.left != null) {
            nodes.push(currentNode);
            currentNode = currentNode.left;
        }
        return ret;
    }
}

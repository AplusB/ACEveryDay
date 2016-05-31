public class Solution {
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */

    private int[][] m;

    private int searchRow(int target) {
        int l = 0, r = m.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (m[mid][0] > target)
                r = mid;
            else
                l = mid + 1;
        }
        if (l == 0 && m[l][0] > target) 
            return -1;
        return --l;
    }

    private boolean searchColumn(int row, int target) {
        int l = 0, r = m[0].length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (m[row][mid] >= target)
                r = mid;
            else 
                l = mid + 1;
        }
        return l != m[0].length && m[row][l] == target;
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return false;
        this.m = matrix;

        int row = searchRow(target);
        if (row == -1)
            return false;
        return searchColumn(row, target);
    }
}


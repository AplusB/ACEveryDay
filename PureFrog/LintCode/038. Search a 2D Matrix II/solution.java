public class Solution {
    /**
     * @param matrix: A list of lists of integers
     * @param: A number you want to search in the matrix
     * @return: An integer indicate the occurrence of target in the given matrix
     */
    public int searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0)
            return 0;
        if (matrix[0].length == 0)
            return 0;

        int ans = 0;
        int row = matrix.length, column = matrix[0].length;
        int currentRow = 0, currentColumn = column - 1;
        while (currentRow >= 0 && currentRow < row && currentColumn >= 0 && currentColumn < column) {
            int currentNumber = matrix[currentRow][currentColumn];
            if (currentNumber > target)
                --currentColumn;
            else if (currentNumber < target)
                ++currentRow;
            else {
                ++ans;
                ++currentRow;
            }
        }
        return ans;
    }
}


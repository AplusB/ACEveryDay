class Solution:
    """
    @param grid: a list of lists of integers.
    @return: An integer, minimizes the sum of all numbers along its path
    """
    def minPathSum(self, grid):
        # write your code here
        r = len(grid)
        c = len(grid[0])
        
        for i in range(r):
            for j in range(c):
                tmp = []
                if i - 1 >= 0:
                    tmp.append(grid[i - 1][j] + grid[i][j])
                if j - 1 >= 0:
                    tmp.append(grid[i][j - 1] + grid[i][j])
                if len(tmp) == 0:
                    pass
                else:
                    grid[i][j] = min(tmp)
                
        return grid[r - 1][c - 1]
        
        
                    

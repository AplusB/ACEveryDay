class Solution:
    """
    @param obstacleGrid: An list of lists of integers
    @return: An integer
    """
    def uniquePathsWithObstacles(self, obstacleGrid):
        # write your code here
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        
        for r in xrange(m):
            for c in xrange(n):
                if r == 0 and c == 0:
                    if obstacleGrid[0][0] != 1:
                        obstacleGrid[0][0] = 1
                    else:
                        obstacleGrid[0][0] = 0
                    continue
                        
                if obstacleGrid[r][c] == 1:
                    obstacleGrid[r][c] = 0;
                else:
                    res = 0
                    if r - 1 >= 0:
                        res += obstacleGrid[r - 1][c]
                    if c - 1 >= 0:
                        res += obstacleGrid[r][c - 1]
                    obstacleGrid[r][c] = res
                    
        return obstacleGrid[m - 1][n - 1]
        
        


class Solution:
    """
    @param triangle: a list of lists of integers.
    @return: An integer, minimum path sum.
    """
    def minimumTotal(self, triangle):
        # write your code here
        n = len(triangle)
        for i  in range(1, n):
            m = len(triangle[i])
            for j in range(m):
                if j == 0:
                    triangle[i][j] += triangle[i - 1][j]
                elif j == m - 1:
                    triangle[i][j] += triangle[i - 1][j - 1]
                else:
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j])
        
        return min(triangle[n - 1])

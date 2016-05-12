def maximalSquare(matrix):
    """
    :type matrix: List[List[str]]
    :rtype: int
    """
    if matrix is None or len(matrix) == 0 or len(matrix[0]) == 0:
        return 0
    n = len(matrix)
    m = len(matrix[0])
    d = [[0] * n] * m
    Max = 0
    for i in range(0, m):
        if matrix[i][0] == '1':
            d[i][0] = 1
            Max = 1
    for j in range(0, n):
        if matrix[0][j] == '1':
            d[0][j] = 1
            #print(d[1])
            Max = 1

    print(d)
    for i in range(1, m):
        for j in range(1, n):
            #print(i,j)
            #print(matrix[i][j])

            if (matrix[i][j] == '1'):
                #d[i][j] = 0
                d[i][j] = min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]) + 1

            Max = max(Max, d[i][j])
            #print(d)
    return Max * Max
if __name__ == '__main__':
    print(maximalSquare(["1010","1011","1011","1111"]))
class Solution:
    # @param m: An integer m denotes the size of a backpack
    # @param A: Given n items with size A[i]
    # @return: The maximum size
    def backPack(self, m, A):
        # write your code here
        A0 = [0] * (m + 1)
        B0 = [0] * (m + 1)
        n = len(A)
        # calc base case
        for x in range(m + 1):
            if A[0] <= x:
                A0[x] = A[0]
        print A0        
        for i in range(1, n):
            
            for x in range(m + 1):
                if A[i] > x:
                    B0[x] = A0[x]
                else:
                    B0[x] = max(A0[x], A[i] + A0[x - A[i]])
            print B0

            A0, B0 = B0, A0
        
        return A0[m]


sol = Solution()

print sol.backPack(10, [3, 4, 8, 5])


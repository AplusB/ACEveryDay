class Solution:
    # @param n: An integer.
    # return : A list of integer storing 1 to the largest number with n digits.
    def numbersByRecursion(self, n):
        if n == 0:
            return []
        elif n == 1:
            return [1, 2, 3, 4, 5, 6, 7, 8, 9]
        else:
            begin = '1' + '0' * (n - 1)
            end = '9' * n
            begin, end = int(begin), int(end)

            res = self.numbersByRecursion(n - 1)
            res.extend(range(begin, end + 1))

            return res

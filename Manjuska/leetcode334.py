class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        big=699999999999
        min_num, a, b = float("inf"), float("inf"), float("inf")
        for x in nums:
            if x <= min_num:
                min_num=x
            elif b>=x:
                a,b=min_num,x
            else:
                return True
        return False

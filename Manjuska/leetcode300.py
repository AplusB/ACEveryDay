# encoding: utf-8
"""
@version: ??
@author: Jeff
@contact: lizheao940510@gmail.com
@software: PyCharm
@file: leetcode300.py
@time: 21:03
"""


def lengthOfLIS(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    if nums == None or len(nums) < 1:
        return 0
    dp=[]
    dp=[]
    dp.append(1)
    max1 = 1
    for i in range(0, len(nums)):
        dp.append(1)
        #print('i=',i)
        #print('dp[i]=',dp[i])
        for j in range(0, i):
            print(dp[j])
            if (nums[j] < nums[i]):
                dp[i] = max(dp[i], dp[j] + 1)
                print(dp[i])
        max1 = max(max1, dp[i])
        print(max1)
    return max1
if __name__=='__main__':
    test=[-2,-1]
    temp=lengthOfLIS(test)
    print(temp)

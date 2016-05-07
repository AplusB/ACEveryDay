class Solution(object):
# partition in place within indices [left, right] inclusive
# change num in place into [...numbers<num[idx]...,numbers==num[idx]...,...numbers>num[idx]... ]
# return the idx after partition
    def partition(self, num, left, right, idx):
        num[idx], num[right] = num[right], num[idx]
        r1,r2 = right, right
        while left<r1:
            if num[left]<num[r1]:
                left += 1
            elif num[left] == num[r1]:
                num[left], num[r1-1] = num[r1-1], num[left]
                r1 -= 1
            elif num[left]>num[r1]:
                num[left], num[r1-1] = num[r1-1], num[left]
                num[r2], num[r1-1] = num[r1-1], num[r2]
                r1 -= 1
                r2 -= 1
        return r1

# again, in place, put kth largest in mid
    def findkth(self, num, k):
        left, right = 0, len(num)-1
        while left<right:
            pivot = (left + right)/2
            idx = self.partition(num, left, right, pivot)
            if num[idx] == num[k]: break
            if idx>k:
                right = idx-1
            else:
                left = idx+1

    def wiggleSort(self, nums):
        mid = len(nums)/2
        self.findkth(nums, mid)       # find median and do partition
        if len(nums)%2 == 0:
            nums[::2], nums[1::2] = nums[:mid][::-1], nums[mid:][::-1]
        else:
            nums[::2], nums[1::2] = nums[:mid+1][::-1], nums[mid+1:][::-1]
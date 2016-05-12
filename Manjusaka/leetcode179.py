
class Solution:
    # @param {integer[]} nums
    # @return {string}
    @classmethod

    def largestNumber(self, nums):
        ret = ''.join(sorted([str(x) for x in nums],cmp=lambda x,y:cmp(y+x,x+y)))
        return ret if ret[0] !='0' else "0"
        
            

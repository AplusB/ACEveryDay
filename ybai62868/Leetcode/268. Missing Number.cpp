class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if ( len==0 ) return 0;
        long long sum1 = (len+1)*len/2;
        long long sum2 = 0;
        for ( int i = 0;i < len;i++ ) sum2+=nums[i];
        return sum1-sum2;
    }
};

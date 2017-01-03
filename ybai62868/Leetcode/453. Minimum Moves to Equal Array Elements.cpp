class Solution {
public:
    int minMoves(vector<int>& nums) {
        int len = nums.size();
        if ( len <= 1 ) return 0;
        long long sum = 0;
        for ( int i = 0;i < len;i++ ) sum+=nums[i];
        int _min = nums[0];
        for ( int i = 1;i < len;i++ ) _min = min(_min,nums[i]);
        int res = sum-len*_min;
        return res;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        int cnt = 0;
        for ( int i = 0;i < len;i++ ) {
            if ( nums[i] ) {
                cnt++;
                res = max(res,cnt);
            }
            else {
                cnt = 0;
            }
        }
        return res;
    }
};

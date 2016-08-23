class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>res;
        int len = nums.size();
        if ( len < 2 ) return false;
        for ( int i = 0;i < len;i++ ){
            if ( res.count(nums[i])&&(i-res[nums[i]]<=k) ) return true;
            res[nums[i]] = i;
        }
        return false;
    }
};

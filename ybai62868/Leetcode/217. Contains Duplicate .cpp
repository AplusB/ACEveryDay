class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        set<int>hash;
        for ( int i = 0;i < len;i++ ) {
            if ( hash.find(nums[i])!=hash.end() ) {
                return true;
            }
            hash.insert(nums[i]);
        }
        return false;
    }
};

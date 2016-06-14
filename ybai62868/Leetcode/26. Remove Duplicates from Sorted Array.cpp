class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if ( len==0 ) return 0;
        int l = 0;
        for ( int r = l;r < len;r++ )
        {
            if ( nums[r]!=nums[l] )
            {
                nums[++l] = nums[r];
            }
        }
        return l+1;
    }
};

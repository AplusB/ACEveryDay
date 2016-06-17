class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if ( n==0 ) return 0;
        int left = 0;
        int right = n-1;
        int mid = 0;
        int pos = -1;
        while ( left <= right )
        {
            mid = (left+right)>>1;
            if ( nums[mid]==target )
            {
                pos = mid;
                break;
            }
            if ( nums[left] <= nums[mid] )
            {
                if ( nums[left] <= target && target < nums[mid] )
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if ( nums[mid] < target && target <= nums[right] )
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return pos;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty()||matrix[0].empty() ) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int lo = 0, hi = row*col - 1;
        while ( lo <= hi ){
            int mid = ( lo+hi)>>1;
            if ( matrix[mid/col][mid%col]==target ){
                return true;
            }
            else if ( matrix[mid/col][mid%col] < target ){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return false;
    }
};

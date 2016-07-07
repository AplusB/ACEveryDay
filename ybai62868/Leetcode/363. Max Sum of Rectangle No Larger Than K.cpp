class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        if ( row==0 ) return 0;
        int col = matrix[0].size();
        if ( col==0 ) return 0;
        int ret = INT_MIN;
        for ( int i = 0;i < col;i++ ){
            vector<int>sum(row,0);
            for ( int j = i;j < col;j++ ){
                for ( int r = 0;r < row;r++ ){
                    sum[r] += matrix[r][j];
                }
                int curSum = 0, curMax = INT_MIN;
                set<int>sumSet;
                sumSet.insert(0);
                for ( int r = 0;r < row;r++ ){
                    curSum += sum[r];
                    auto it = sumSet.lower_bound(curSum-k);
                    if ( it!=sumSet.end()) curMax = max(curMax,curSum-*it);
                    sumSet.insert(curSum);
                }
                ret = max(ret,curMax);
            }
        }
        return ret;
    }
};

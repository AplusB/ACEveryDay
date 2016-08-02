class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>heap;
        for ( int i = 0;i < matrix.size();i++ ) {
            for ( int j = 0;j < matrix[0].size();j++ ) {
                if ( heap.size() < k ) heap.push(matrix[i][j]);
                else {
                    heap.push(matrix[i][j]);
                    heap.pop();
                }
            }  
        }  
        return heap.top();
    }
};

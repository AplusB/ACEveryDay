class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int n = (int)A.size();
        if (n == 1) return true;
        vector<bool> F(n);
        for (auto i: F) {
            i = false;
        }
        
        F[0] = true;
        for(int i = 0; i < n - 1; i++) {
            if (F[i]) {
                for (int j = 1; j <= A[i]; j++) {
                    F[i + j] = true;
                    if (i + j == n - 1) return true;
                }
            }
        }
        return false;
    }
};


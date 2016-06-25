class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        vector<int> A0(m + 1);
        vector<int> B0(m + 1);
        
        int n = A.size();
        for (int x = 0; x < m + 1; x++) {
            if (A[0] <= x) {
                A0[x] = A[0];
            } else A0[x] = 0;
        }
        
        for (int i = 1; i < n; i++) {
            for (int x = 0; x < m + 1; x++) {
                if (A[i] > x) B0[x] = A0[x];
                else {
                    if (A0[x] > A[i] + A0[x - A[i]]) B0[x] = A0[x];
                    else B0[x] = A[i] + A0[x - A[i]];
                }
            }
            A0.swap(B0);
        }
        
        return A0[m];
    }
};

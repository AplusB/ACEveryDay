using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<int> P1(m + 3);
        vector<int> P2(m + 3);
        
        int n = A.size();
        
        for (int i = 0; i <= m; i++) {
            if (i < A[0]) {
                P1[i] = 0;
            } else {
                P1[i] = V[0];
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int x = 0; x <= m; x++) {
                if (x >= A[i]) {
                    P2[x] = max(P1[x], V[i] + P1[x - A[i]]);
                } else {
                    P2[x] = P1[x];
                }
            }
            P1.swap(P2);
        }
        
        return P1[m];
    }
};

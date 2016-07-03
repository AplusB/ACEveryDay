#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        vector<int> dp(n + 1);
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int sq = int(sqrt(i*1.0));
            
            if (sq*sq == i) {
                dp[i] = 1;
            } else {
                int res = dp[1] + dp[i - 1];
                for (int j = 1; j*j <= i; j++) {
                    res = min(res, dp[j * j] + dp[i - j * j]);
                }
                dp[i] = res;
            }
        }
        
        return dp[n];
        
    }
};

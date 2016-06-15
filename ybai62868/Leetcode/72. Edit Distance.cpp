class Solution {
public:
    int ok ( char s1,char s2 )
    {
        if ( s1==s2 ) return 0;
        return 1;
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for ( int i = 0;i <= m;i++ )
        {
            for ( int j = 0;j <= n;j++ )
            {
                if ( i==0 )
                {
                    dp[i][j] = j;
                }
                else if ( j==0 )
                {
                    dp[i][j] = i;
                }
                else
                {
                    dp[i][j] = min((dp[i-1][j-1]+ok(word1[i-1],word2[j-1])),min(dp[i][j-1]+1,dp[i-1][j]+1));
                }
            }
        }
        return dp[m][n];
    }
};

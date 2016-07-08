class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>result;
        if(nums.size() ==0) return result;
        sort(nums.begin(), nums.end(), greater<int>());
        int len = nums.size(), curMax=1, k=0;
        vector<int> par(len), dp(len, 1);
        for(int i =0; i < len; i++) par[i] = i;
        for(int i =1; i < len; i++)
        {
            for(int j =0; j < i; j++)
            {
                if(nums[j]%nums[i]!=0) continue;
                if(dp[i] < dp[j]+1) par[i] = j, dp[i]=dp[j]+1;
                if(dp[i] > curMax) curMax = dp[i], k = i;
            }
        }
        while(par[k] != k)
        {
            result.push_back(nums[k]);
            k = par[k];
        }
        result.push_back(nums[k]);
        return result;
    }
};

class Solution {
public:
    vector<int>ans;
    vector<vector<int>>res;
    set<int>s;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        if ( len==0 ) return res;
        dfs(0,nums);
        return res;
    }
    void dfs( int step,vector<int> nums )
    {
        if ( step==nums.size() )
        {
            res.push_back(ans);
            return;
        }
        for ( int i = 0;i < nums.size();i++ )
        {
            if ( s.find(nums[i])!=s.end() ) continue;
            s.insert(nums[i]);
            ans.push_back(nums[i]);
            dfs(step+1,nums);
            ans.pop_back();
            s.erase(nums[i]);
        }
    }
};

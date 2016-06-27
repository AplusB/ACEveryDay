class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vis[100010];
        memset(vis, 0, sizeof(vis));
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end()); tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for(int i = 0; i < nums.size(); i++) {
            int id = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
            vis[id]++;
        }
        for(int i = 0; i < tmp.size(); i++) {
            if(vis[i] > nums.size() / 2) return tmp[i];
        }
        return -1;
    }
};

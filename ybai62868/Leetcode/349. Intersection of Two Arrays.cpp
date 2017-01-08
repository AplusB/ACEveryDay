class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>S(nums1.begin(),nums1.end());
        vector<int>res;
        for ( auto temp:nums2 ) {
            if ( S.count(temp) ) {
                res.push_back(temp);
                S.erase(temp);
            }
        }
        return res;
    }
};

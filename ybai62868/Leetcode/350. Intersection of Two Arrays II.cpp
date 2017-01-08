class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>MP;
        for ( auto temp:nums1 ) {
            MP[temp]++;
        }
        vector<int>res;
        for ( auto temp2:nums2 ) {
            if ( MP[temp2]-- > 0 ) {
                res.push_back(temp2);
            }
        }
        return res;
    }
};

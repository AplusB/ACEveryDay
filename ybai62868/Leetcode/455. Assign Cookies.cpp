class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int len1 = g.size();
        int len2 = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res = 0;
        int j = 0;
        for ( int i = 0;i < len2;i++ ) {
            if ( j < len1&&s[i] >= g[j] ) res++,j++;
        }
        return res;
        
    }
};

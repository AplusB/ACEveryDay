class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if ( len1+len2 != len3 ) return false;
        vector<vector<char> >isMatch(len1+1,vector<char>(len2+1,0));
        isMatch[0][0] = 1;
        for ( int i = 0;i <= len1;i++ ){
            for ( int j = 0;j <= len2;j++ ){
                if ( i!=0&&isMatch[i-1][j] ) isMatch[i][j]|=(s1[i-1]==s3[i+j-1]);
                if ( j!=0&&isMatch[i][j-1] ) isMatch[i][j]|=(s2[j-1]==s3[i+j-1]);
            }
        }
        return isMatch[len1][len2];
    }
};

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        if ( len==0 ) return false;
        vector<bool>isMatch(len+1,false);
        isMatch[0] = true;
        for ( int i = 1;i <= len;i++ ){
            for ( int j = 0;j < i;j++ ){
                if ( isMatch[j] && wordDict.find(s.substr(j,i-j))!=wordDict.end()){
                    isMatch[i] = true;
                    break;
                }
            }
        }
        return isMatch[len];
    }
};

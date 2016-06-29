class Solution {
    bool ok( string s ){
        int l = 0, r = s.size()-1;
        while ( s[l]==s[r] ){
            l++;
            r--;
        }
        return l > r;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ret;
        unordered_map<string,int>hash;
        for ( int i = 0;i < words.size();i++ ) hash[words[i]] = i;
            for ( int i = 0;i < words.size();i++ ){
                for ( int j = 0;j <= words[i].size();j++ ){
                    string ls = words[i].substr(0,j);
                    string rs = words[i].substr(j);
                    if ( ok(ls) ){
                        reverse(rs.begin(),rs.end());
                        if ( hash.find(rs)!=hash.end()&&hash[rs]!=i ){
                            ret.push_back(vector<int>{hash[rs],i});
                        }
                    }
                    if ( !rs.empty()&&ok(rs) ){
                        reverse(ls.begin(),ls.end());
                        if ( hash.find(ls)!=hash.end()&&hash[ls]!=i ){
                            ret.push_back(vector<int>{i,hash[ls]});
                        }
                    }
                }
            }
        return ret;
    }
};

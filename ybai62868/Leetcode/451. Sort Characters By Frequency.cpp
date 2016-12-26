class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(256,0);
        vector<string>bucket(s.size()+1,"");
        string res = "";
        for(auto ch:s) {
            freq[ch]++;
        }
        for ( int i = 0;i < 256;i++ ) {
            bucket[freq[i]]+=string(freq[i],i);
        }
        for ( int i = bucket.size()-1;i>0;i-- ) {
            res+=bucket[i];
        }
        return res;
    }
};

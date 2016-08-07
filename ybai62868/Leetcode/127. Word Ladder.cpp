class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string>next;
        int length = 1;
        next.push(beginWord);
        while ( !next.empty() ) {
            int sz = next.size();
            for ( int i = 0;i < sz;i++ ) {
                string cur = next.front();
                next.pop();
                if ( cur==endWord ) return length;
                else {
                    for ( int j = 0;j < cur.size();j++ ) {
                        char c = cur[j];
                        for ( char ch = 'a';ch <= 'z';ch++ ) {
                            cur[j] = ch;
                            if ( wordList.find(cur)!=wordList.end() ) {
                                next.push(cur);
                                wordList.erase(cur);
                            }
                        }
                        cur[j] = c;
                    }
                }
            }
            length++;
        }
        return 0;
    } 
};

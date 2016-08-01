class Solution {
public:
    void reverseWords(string &s) {
        stack<string>words;
        string curWord = "";
        s+=" ";
        for ( int i = 0;i < s.size();i++ ) {
            if ( s[i]==' ' ) {
                if ( !curWord.empty() ) {
                    words.push(curWord);
                    curWord = "";
                }
            }
            else curWord += s[i];
        }
        s = "";
        while ( !words.empty() ) {
            s+=words.top();
            words.pop();
            if (!words.empty()) s+=" ";
        }
    }
};

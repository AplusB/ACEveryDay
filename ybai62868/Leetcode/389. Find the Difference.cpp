class Solution {
public:
    char findTheDifference(string s, string t) {
        int i;
        int count_s = 0, count_t = 0;
        for (i = 0; i < s.size(); i++) {
            count_s += int(s[i] - 'a');
        }
        for (i = 0; i < t.size(); i++) {
            count_t += int(t[i] - 'a');
        }
        return 'a' + (count_t - count_s);
    }
};

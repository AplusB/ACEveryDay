class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if (num < 0 || num > 8) return res;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (bitset<16>((j << 4) + i).count() == num) {
                    string t = to_string(i) + ":";
                    if (j < 10) t.push_back('0');
                    t += to_string(j);
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};

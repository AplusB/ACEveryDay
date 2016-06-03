#include <bits/stdc++.h>
using namespace std;

const int  MOD = (int) 1e9 + 7;
int  cnt[64];
int main() {
        string s;
        cin >> s;
        map<char, int> mp;
        for(int i = 0; i < 10; i++) mp['0'+i] = i;
        for(int i = 0; i < 26; i++) mp['A'+i] = 10 + i;
        for(int i = 0; i < 26; i++) mp['a'+i] = 36 + i;
        mp['-'] = 62;
        mp['_'] = 63;
        for(int i = 0; i < 64; i++) {
                for(int j = 0; j < 64; j++) {
                        cnt[i & j]++;
                }
        }
        long long ret = 1;
        for(int i = 0; i < s.length(); i++) {
                int num = mp[s[i]];
                ret = ret * cnt[num] % MOD;
        }
        cout << ret << endl;
        return 0;
}

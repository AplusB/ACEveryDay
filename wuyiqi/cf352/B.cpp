#include <bits/stdc++.h>

using namespace std;
int cnt[26];
int main() {
        int n; 
        string s;
        cin >> n;
        cin >> s;
        if(n > 26) {
                puts("-1");
                return 0;
        }
        for(int i = 0; i < n; i++) {
                cnt[s[i]-'a']++;
        }
        int ret = 0;
        for(int i = 0; i < 26; i++) if(cnt[i])
                ret += cnt[i] - 1;
        cout << ret <<  endl;
        return 0;
}

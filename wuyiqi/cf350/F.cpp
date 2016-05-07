#include <bits/stdc++.h>

std::string s;
int cnt[10];
int main()
{
    std::cin >> s;
    for(int i = 0; i < s.length(); i++) {
        cnt[s[i]-'0']++;
    }
    std::string t;
    std::cin >> t;
    std::string ret = "";
    for(int i = 0; i < t.length(); i++) {
        cnt[t[i]-'0']--;
    }
    bool flag = false;
    for(int i = 1; i < t.length(); i++) {
        if(t[i] < t[0]) {
            flag = true;
        }
    }
    for(int i = 0; i < t[0]-'0'; i++) {
        if(i) {
            ret += i + '0';
            cnt[i]--;
            break;
        }
    }
    for(int i = 0; i < t[0]-'0'; i++) {
        for(int j = 0; j < cnt[i]; j++) {
            ret += '0' + i;
            cnt[i]--;
        }
    }
    if(!flag) {
        for(int i = 0; i < cnt[t[0]-'0']; i++) {
            ret += t[0];
            cnt[t[0]-'0']--;
        }
    }
    ret += t;
    for(int i = 0; i < cnt[t[0]-'0']; i++) {
        ret += t[0];
        cnt[t[0]-'0']--;
    }
    for(int i = t[0]-'0' + 1; i < 10; i++) {
        for(int j = 0; j < cnt[i]; j++) {
            ret += i + '0';
            cnt[i]--;
        }
    }
    std::cout << ret << std::endl;
    return 0;
}

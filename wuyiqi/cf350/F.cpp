#include <bits/stdc++.h>

std::string s, t, ret;
std::vector<std::string> candidates;
int cnt[10];
void PushBackAll(int i)
{
    for(int j = 0; j < cnt[i]; j++) {
        ret += i + '0';
    }
}

int main()
{
    std::cin >> s;
    for(int i = 0; i < s.length(); i++) {
        cnt[s[i]-'0']++;
    }
    std::cin >> t;
    ret = "";
    for(int i = 0; i < t.length(); i++) {
        cnt[t[i]-'0']--;
    }
    int tot = -1;
    for(int i = 1; i <= 6; i++) {
        int num = (int)s.length() - i;
        int dig = 0;
        for(;num;num/=10) dig++;
        if(dig == i) {
            tot = (int)s.length() - i;
            break;
        }
    }
    for(;tot;tot/=10) cnt[tot%10]--;
    //前面不放
    ret += t;
    for(int i = 0; i < 10; i++)
        PushBackAll(i);
    candidates.push_back(ret);

    ret = "";
    //前面要放,先确定首位的数字
    for(int i = 1; i < 10; i++) {
        if(cnt[i]) {
            ret += '0' + i;
            cnt[i]--;
            break;
        }
    }
    std::string tmp = ret;

    //小于等于t[0]的数放前面
    for(int i = 0; i <= t[0]-'0'; i++) {
        PushBackAll(i);
    }
    ret += t;
    for(int i = t[0]-'0'+1; i < 10; i++) {
        PushBackAll(i);
    }
    candidates.push_back(ret);

    //小于等于t[0]的数放后面
    ret = tmp;
    for(int i = 0; i < t[0]-'0'; i++) {
        PushBackAll(i);
    }
    ret += t;
    for(int i = t[0]-'0'; i < 10; i++) {
        PushBackAll(i);
    }
    candidates.push_back(ret);

    ret = "";
    for(auto it : candidates) {
        if(it[0] != '0' || it.length() == 1) {
            if(ret == "" || it < ret ) {
                ret = it;
            }
        }
    }

    std::cout << ret << std::endl;
    return 0;
}

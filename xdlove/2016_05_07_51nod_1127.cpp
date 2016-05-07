/* ***********************************************
Author        :xdlove
Created Time  :2016年05月07日 星期六 22时04分23秒
File Name     :2016_05_07_51nod_1127.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int a[26];

void solve()
{
    string s;
    int ans = 100006;
    cin>>s;
    int l = 0,cnt = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        if(a[s[i] - 'A'] == 0) cnt++;
        a[s[i] - 'A']++;
        while(cnt == 26)
        {
            ans = min(ans,i - l + 1);
            a[s[l] - 'A']--;
            if(a[s[l] - 'A'] == 0)
                cnt--;
            l++;
        }
    }
    if(ans > 100000)
    {
        cout << "No Solution" << endl;
    }
    else cout << ans << endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();    
    return 0;
}

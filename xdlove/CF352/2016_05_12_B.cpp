/* ***********************************************
Author        :xdlove
Created Time  :2016年05月12日 星期四 08时21分19秒
File Name     :CF352/2016_05_12_B.cpp
************************************************ */

#pragma comment(linker, "/STACK:1024000000,1024000000")
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

void solve()
{
    int n,ans;
    string s;
    cin >> n >> s;
    map<int,int> mp;
    ans = s.length();
    if(ans > 26) ans = -1;
    else 
    for(int i = 0; i < n; ++i)
    {
        if(mp[s[i]] == 0)
        {
            --ans;
            mp[s[i]] = 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();    
    return 0;
}

/* ***********************************************
Author        :xdlove
Created Time  :2016年05月09日 星期一 08时24分46秒
File Name     :2016_05_08_51nod_1179.cpp
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

const int N = 1e6 + 6;
int mp[N];

void solve()
{
    int n;
    cin>>n;
    memset(mp,0,sizeof(mp));
    for(int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d",&x);
        mp[x] = 1;
    }
    int ans = 1;
    for(int i = 2; i <= 1000000; ++i)
    {
        int cnt = 0;
        for(int j = i; j <= 1000000; j += i)
        {
            if(mp[j]) cnt++;
        }
        if(cnt > 1) ans = i;
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

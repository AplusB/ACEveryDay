/* ***********************************************
Author        :xdlove
Created Time  :2016年05月19日 星期四 19时52分02秒
File Name     :2016_05_19_51nod_1483.cpp
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

const int N = 1e5 + 5;
int mp[N];
int vis[N];

void work(int x,int num)
{
    while(x * 2 < N)
    {
        num++;
        x <<= 1;
        mp[x] += num;
        vis[x]++;
    }
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x,num = 0;
        scanf("%d",&x);
        vis[x]++;
        while(x)
        {
            work(x,num);
            while(x % 2 == 0)
            {
                x >>= 1;
                num++;
                mp[x] += num;
                vis[x]++;
            }
            x >>= 1;
            num++;
            mp[x] += num;
            vis[x]++;
        }
    }
    int num = 1<<30;
    for(int i = 1; i < N; ++i)
    {
        if(mp[i] != -1 && vis[i] == n)
            num = min(num,mp[i]);
    }
    cout << num << endl;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();    
    return 0;
}

/* ***********************************************
Author        :xdlove
Created Time  :2016年05月10日 星期二 20时27分30秒
File Name     :2016_05_10_1213_Fantasy_of_a_Summation.cpp
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

int Pow(int n,int k,int mod)
{
    int res = 1;
    while(k)
    {
        if(k & 1) res = 1LL * res * n % mod;
        n = 1LL * n * n % mod;
        k >>= 1;
    }
    return res;
}

void solve()
{
    int T,n,k,mod;
    int cnt = 1;
    cin >> T;
    while(T--)
    {
        scanf("%d %d %d",&n,&k,&mod);
        int ans = Pow(n,k - 1,mod);
        int sum = 0,x;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d",&x);
            sum = (0LL + sum + x) % mod;
        }
        ans = 1LL * ans * sum % mod;
        ans = 1LL * ans * k % mod;
        printf("Case %d: %d\n",cnt++,ans);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();    
    return 0;
}

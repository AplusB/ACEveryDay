/* ***********************************************
Author        :xdlove
Created Time  :2016年05月14日 星期六 07时52分21秒
File Name     :2016_05_14_51nod_1670.cpp
************************************************ */

//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef long long ll;
const int mod = 1e9 + 7;
int mp[N],fact[N];

void Fact(int n)
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= n; ++i)
        fact[i] = 1LL * fact[i - 1] * i % mod;
}

void solve()
{
    memset(mp, 0, sizeof mp);
    int n,i;
    cin >> n;
    Fact(n);
    for(i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d",&x);
        mp[x]++;
    }
    ll ans = 0,tp = 1;
    int num = 0;
    for(i = 0; i < n; ++i)
    {
        num += mp[i];
        if(num - i == 0) break;
        if(n - num)
        {
            ans = (ans + tp * (n - num) % mod * fact[n - i - 1] % mod * i % mod) % mod;
        }
        tp = tp * (num - i) % mod;
    }
    if(num - i + 1 > 0)
    {
        ans = (ans + tp * i % mod * fact[n - i] % mod) % mod;
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

/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=1e5+10;
ll p[N][35],s[N][35],m[N][35],f[35];
int n;
ll k;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%lld",&n,&k);
    memset(p,0,sizeof(p));
    memset(s,0,sizeof(s));
    //memset(m,0x3f,sizeof(m));
    f[0]=1;
    for(int i=1;i<35;i++)
        f[i]=f[i-1]*2;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&p[i][0]);
        p[i][0]++;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i][0]);
        m[i][0]=s[i][0];
    }
    for(int i=1;i<35;i++)
    {
        for(int j=1;j<=n;j++)
        {
            p[j][i]=p[p[j][i-1]][i-1];
            s[j][i]=s[j][i-1]+s[p[j][i-1]][i-1];
            m[j][i]=min(m[j][i-1],m[p[j][i-1]][i-1]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        ll x=0,y=1e9;
        int q=i;
        for(int j=34;j>=0;j--)
        {

            if(f[j]&k)
            {
                x+=s[q][j];
                y=min(y,m[q][j]);
                q=p[q][j];
            }
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}

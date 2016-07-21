//poj1163
//#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=1e2+10;

int dp[N][N];
int a[N][N];
int n;

int dfs(int x,int y)
{
    if(dp[x][y]!=-1)
        return dp[x][y];
    int ans=0;
    if(x-1>=1)
        ans=max(dfs(x-1,y),ans);
    if(y-1>=1&&x-1>=1)
        ans=max(dfs(x-1,y-1),ans);
    return dp[x][y]=(ans+a[x][y]);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    int ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
        ans=max(dfs(n,i),ans);
    cout<<ans<<endl;
}



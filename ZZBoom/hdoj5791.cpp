//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);

const LL mod=1000000007;
const int INF=0x3f3f3f3f;

const int N=1e3+10;
int a[N],b[N];
LL dp[N][N];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int i,j;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i]==b[j])
                    dp[i][j]=((dp[i-1][j]+dp[i][j-1])%mod+1)%mod;
                else
                    dp[i][j]=((dp[i-1][j]+dp[i][j-1])%mod-dp[i-1][j-1]+mod)%mod;
            }
        }
        printf("%lld\n",dp[n][m]%mod);
    }
    return 0;
}
/*
2 2
1 1
1 1



*/

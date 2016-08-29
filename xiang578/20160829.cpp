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
const int N=100+10;
const int M=1e6+10;
ll dp[N][N][N],c[N],a[N][N];
int n,m,k;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++) scanf("%lld",&c[i]);
    for(int i=0; i<n; i++)
        for(int j=1; j<=m; j++)
            scanf("%lld",&a[i][j]);
    memset(dp,0xff,sizeof(dp));
    if(c[0]==0)
    {
        for(int i=1; i<=m; i++)
            dp[0][i][1]=a[0][i];
    }
    else
    {
        dp[0][c[0]][1]=0;
    }
    for(int p=1; p<=k; p++)
    {
        for(int i=1; i<n; i++)
        {
            if(c[i]!=0)
            {
                for(int j=1; j<=m; j++)
                {
                    //printf("%d %d %lld\n",i,j,dp[i-1][j][p]);
                    if(dp[i-1][j][p]==-1) continue;
                    if(j==c[i])
                    {
                        if(dp[i][j][p]==-1) dp[i][j][p]=dp[i-1][j][p];
                        else dp[i][j][p]=min(dp[i][j][p],dp[i-1][j][p]);
                    }
                    else
                    {
                        if(dp[i][c[i]][p+1]==-1) dp[i][c[i]][p+1]=dp[i-1][j][p];
                        else dp[i][c[i]][p+1]=min(dp[i][c[i]][p+1],dp[i-1][j][p]);
                    }
                }
            }
            else
            {
                for(int j=1; j<=m; j++)
                {
                    if(dp[i-1][j][p]==-1) continue;
                    for(int t=1; t<=m; t++)
                    {
                        if(j==t)
                        {
                            if(dp[i][t][p]==-1) dp[i][t][p]=dp[i-1][j][p]+a[i][t];
                            else dp[i][t][p]=min(dp[i][t][p],dp[i-1][j][p]+a[i][t]);
                        }
                        else
                        {
                            if(dp[i][t][p+1]==-1) dp[i][t][p+1]=dp[i-1][j][p]+a[i][t];
                            else dp[i][t][p+1]=min(dp[i][t][p+1],dp[i-1][j][p]+a[i][t]);
                        }
                    }
                }
            }
        }
    }
    ll ans=-1;
    for(int i=1; i<=m; i++)
    {
        if(dp[n-1][i][k]==-1) continue;
        if(ans==-1) ans=dp[n-1][i][k];
        else ans=min(ans,dp[n-1][i][k]);
        //printf("%d %lld\n",i,dp[n-1][i][k]);
    }
    cout<<ans<<endl;
    return 0;
}

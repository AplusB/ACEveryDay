#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define N 100100
#define INF 0x7fffffff
#define endl '\n'
#define ll long long
#define mod 9875321
long long a[2010][2010],dp[2010][2010],L[2010][2010],R[2010][2010];
int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        int l=1,r=1;
        for(int j=2;j<=m+1;j++)
        {
            if(j==m+1||a[i][j]==a[i][j-1])
            {
                for(int k=l;k<=r;k++) dp[i][k]=k-l+1;
                l=j,r=j;
            }
            else r++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int l=1,r=1;
        for(int j=2;j<=n+1;j++)
        {
            if(j==n+1||a[j][i]==a[j-1][i])
            {
                for(int k=l;k<=r;k++) L[k][i]=k-l,R[k][i]=r-k;
                l=j,r=j;
            }
            else r++;
        }
    }
    ll ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dp[i][j]!=1) L[i][j]=min(L[i][j],L[i][j-1]),R[i][j]=min(R[i][j],R[i][j-1]);
            ans2=max(ans2,(L[i][j]+R[i][j]+1)*dp[i][j]);
            ans1=max(ans1,min(L[i][j]+R[i][j]+1,dp[i][j])*min(dp[i][j],L[i][j]+R[i][j]+1));
        }
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}

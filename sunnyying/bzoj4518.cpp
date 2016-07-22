#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 2100+10
#define INF 0x3f3f3f3f
#define endl '\n'
#define mod 1000000007
#define ll long long
#define eps 1e-8
using namespace std;
int n,m,head,tail,q[3300];
ll dp[3300][3300],all,sum[3300],a[3300];
ll getdp(int i,int x,int y)
{
    return dp[i-1][y]+(sum[x]-sum[y])*(sum[x]-sum[y]);
}
ll getup(int i,int x,int y)
{
    return dp[i-1][x]+sum[x]*sum[x]-(dp[i-1][y]+sum[y]*sum[y]);
}
ll getdown(int x,int y)
{
    return 2*(sum[x]-sum[y]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i],all+=a[i];
    dp[0][0]=0;
    for(int i=1;i<=n;i++) dp[0][i]=INF;
    for(int j=1;j<=m;j++)
    {
        q[0]=head=0;tail=1;dp[j][0]=0;
        for(int i=1;i<=n;i++)
        {
            while(head+1<tail&&getup(j,q[head+1],q[head])<=sum[i]*getdown(q[head+1],q[head])) head++;
            dp[j][i]=getdp(j,i,q[head]);
            while(head+1<tail&&getup(j,i,q[tail-1])*getdown(q[tail-1],q[tail-2])<=getup(j,q[tail-1],q[tail-2])*getdown(i,q[tail-1])) tail--;
            q[tail++]=i;
        }
    }
    cout<<dp[m][n]*m-all*all<<endl;
    return 0;
}

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
#define mod 1000000007
const int MAXN=500010;
ll a[MAXN],b[MAXN],d[MAXN],c[MAXN],dp[MAXN],l[MAXN],r[MAXN];
vector<int>v[MAXN];
int Search(ll num,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num>=b[mid])  low=mid+1;
        else   high=mid-1;
    }
    return low;
}
int DP(int n)
{
    int i,len,pos;
    b[1]=a[1];
    len=1;d[1]=1;v[1].push_back(1);
    for(i=2;i<=n;i++)
    {
        if(a[i]>=b[len])
        {
            len=len+1;
            b[len]=a[i];
            d[i]=len;
            v[len].push_back(i);
        }
        else
        {
            pos=Search(a[i],1,len);
            b[pos]=a[i];
            v[pos].push_back(i);
            d[i]=pos;
        }
    }
    return len;
}
int main()
{
   // freopen("in.in","r",stdin);
 //   freopen("out.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]),a[i]=c[i]-i;
    a[++n]=(1<<30);
    int len=DP(n);
    ll ans=0;dp[0]=0;a[0]=-(1<<30);
    v[0].push_back(0);
    for(int i=1;i<=n;i++)
    {
        int x=d[i]-1;dp[i]=((ll)(1)<<60);
        for(int j=0;j<v[x].size();j++)
        {

            int xx=v[x][j];
            if(xx>i) continue;
            if(a[xx]>a[i]) continue;
            l[xx]=r[i]=0;
            for(int k=xx+1;k<i;k++) l[k]=abs(a[k]-a[xx])+l[k-1];
            for(int k=i-1;k>xx;k--) r[k]=abs(a[k]-a[i])+r[k+1];
            for(int k=xx;k<i;k++) dp[i]=min(dp[i],dp[xx]+l[k]+r[k+1]);
        }
    }
    cout<<n-len<<endl<<dp[n]<<endl;
    return 0;
}

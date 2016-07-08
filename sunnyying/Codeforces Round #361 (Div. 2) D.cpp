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
#define N 301000
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
using namespace std;
int a[N],b[N],c[N];
int dp[N][50],d[N][50],n;
void RMQ_init()
{
    for(int i=1; i<=n; i++) dp[i][0]=a[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return max(dp[L][k],dp[R-(1<<k)+1][k]);
}
void rmq_init()
{
    for(int i=1; i<=n; i++) d[i][0]=b[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int rmq(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return min(d[L][k],d[R-(1<<k)+1][k]);
}
struct node
{
    int l,r,x;
}D[N];
bool cmp(node a,node b)
{
    if(a.x==b.x) return a.r<b.r;
    return a.x<b.x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    rmq_init();
    RMQ_init();
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n,l1=i,r1=i-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int xx=rmq(i,mid),yy=RMQ(i,mid);
            if(xx>yy) l=mid+1;
            else
            {
                r=mid-1;
                if(xx==yy) l1=mid;
            }
        }
        l=i,r=n;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int xx=rmq(i,mid),yy=RMQ(i,mid);
            if(xx>=yy)
            {
                l=mid+1;
                if(xx==yy) r1=mid;
            }
            else  r=mid-1;
        }
        if(r1>=l1) ans=ans+(r1-l1+1);
    }
    cout<<ans<<endl;
    return 0;
}
/*
17
9 0 9 1 10 4 4 0 5 2 9 5 6 1 2 7 0
3 0 0 9 5 8 8 8 3 3 6 1 7 8 5 8 2
*/

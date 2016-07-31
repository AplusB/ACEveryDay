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
#define INF 0x7fffffff
#define endl '\n'
#define ll long long
#define eps 1e-8
#define N 5000100
using namespace std;
struct node
{
    int x,y,c1,c2;
}a[300000];
int pre[20000],k,m,n;
int fi(int x)
{
    if(pre[x]==-1) return x;
    return pre[x]=fi(pre[x]);
}
int judge(int x)
{
    int sum=0,sum1=0;
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<m;i++)
    {
        if(a[i].c1>x) continue;
        int xx=fi(a[i].x),yy=fi(a[i].y);
        if(xx==yy) continue;
        sum++;sum1++;
        pre[xx]=yy;
    }
    for(int i=1;i<m;i++)
    {
        if(a[i].c2>x) continue;
        int xx=fi(a[i].x),yy=fi(a[i].y);
        if(xx==yy) continue;
        sum1++;
        pre[xx]=yy;
    }
   // cout<<x<<" "<<sum<<" "<<sum1<<endl;
    if(sum1!=n-1||sum<k) return 0;
    return 1;
}
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<m;i++) scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].c1,&a[i].c2);
    int l=1,r=30000,ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(judge(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}

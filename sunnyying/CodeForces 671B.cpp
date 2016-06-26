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
#define N 250010
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
#define mod 1000000007
using namespace std;
struct node
{
    ll x,sum,l,r,mx,mi;
}v[N*4];
ll L[N][2],R[N][2],a[N];
ll H[N];
void f(ll x,ll i)
{
    if(!L[x][0]) L[x][0]=i;
    else if(!L[x][1]) L[x][1]=i;
    R[x][1]=R[x][0],R[x][0]=i;
}
void build(ll i,ll l,ll r)
{
    v[i].l=l,v[i].r=r,v[i].x=0,v[i].sum=0;
    if(l==r){v[i].mi=v[i].mx=v[i].x=l,v[i].sum=l;return;}
    build(i*2,l,(l+r)>>1);
    build(i*2+1,((l+r)>>1)+1,r);
    v[i].sum=v[i*2+1].sum+v[i*2].sum;
    v[i].mx=max(v[i*2].mx,v[i*2+1].mx);
    v[i].mi=min(v[i*2].mi,v[i*2+1].mi);
}
void change(ll i,ll x,ll y,ll s)
{
    if(v[i].mi>=s) return;
    if(y<x) return;
    ll l=v[i].l,r=v[i].r,mid=(l+r)>>1;
    if(l==x&&r==y&&v[i].mx<=s)
    {
        v[i].mi=v[i].mx=v[i].x=s;
        v[i].sum=v[i].x*(r-l+1);
        return;
    }
    else if(l==x&&y==r&&v[i].x==v[i].mx) return;
    if(l==r) return;
    if(v[i].x!=0) change(i*2,l,mid,v[i].x),change(i*2+1,mid+1,r,v[i].x),v[i].x=0;
    if(x>mid) change(i*2+1,x,y,s);
    else if(y<=mid) change(i*2,x,y,s);
    else change(i*2,x,mid,s),change(i*2+1,mid+1,y,s);
    v[i].sum=v[i*2].sum+v[i*2+1].sum;
    v[i].mx=max(v[i*2].mx,v[i*2+1].mx);
    v[i].mi=min(v[i*2].mi,v[i*2+1].mi);
}
int main()
{
   // freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    ll n,mx=0;
    scanf("%I64d",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        ll x=a[i];mx=max(mx,x);
        for(ll j=1;j*j<=x;j++)
        {
            if(x%j) continue;
            ll y=x/j;f(j,i);
            if(y!=j) f(y,i);
        }
    }
    build(1,1,n);
    ll ans=0;
    H[mx+1]=n*(n+1)-v[1].sum;
    for(ll i=mx;i>0;i--)
    {
        if(L[i][0]!=R[i][0])
        {
            change(1,1,L[i][0],R[i][1]);
            change(1,L[i][0]+1,L[i][1],R[i][0]);
            change(1,L[i][1]+1,n,n+1);
        }
        H[i]=(ll)n*(n+1)-v[1].sum;
    }
    if(n==1) H[0]=1;
    else H[0]=3;
    for(ll i=mx;i>0;i--) ans=ans+(H[i+1]-H[i])*i;
    printf("%I64d\n", ans);
    return 0;
}

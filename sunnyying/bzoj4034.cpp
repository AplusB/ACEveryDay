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
#define N 100100
using namespace std;
int fa[N],size[N],dep[N],mark[N],top[N],son[N],sum,R[N];
ll val[N];
vector<int>v[N];
int a[N];
struct node
{
    int l,r;
    ll sum,x;
}tree[N*10];
void dfs_1(int x)
{
    size[x]=1;son[x]=0;
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i];
        if(xx==fa[x]) continue;
        fa[xx]=x;
        dep[xx]=dep[x]+1;
        dfs_1(xx);
        if(size[xx]>size[son[x]]) son[x]=xx;
        size[x]+=size[xx];
    }
    return;
}
void dfs_2(int x,int tp)
{
    sum++;
    mark[x]=sum;top[x]=tp;R[x]=sum;
    if(son[x]!=0) dfs_2(son[x],top[x]),R[x]=max(R[x],R[son[x]]);
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i];
        if(xx!=son[x]&&xx!=fa[x]) dfs_2(xx,xx),R[x]=max(R[x],R[xx]);
    }
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r,tree[i].sum=0,tree[i].x=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    return;
}
void change(int i,int x,int y,ll s)
{

    int l=tree[i].l,r=tree[i].r;
    int mid=(l+r)>>1;
    if(l>=x&&y>=r)
    {
        tree[i].x+=s;
        tree[i].sum=tree[i].sum+(ll)s*(r-l+1);
        return;
    }
    if(tree[i].x!=0&&l!=r) change(i*2,l,mid,tree[i].x),change(i*2+1,mid+1,r,tree[i].x),tree[i].x=0;
    if(y<=mid) change(i*2,x,y,s);
    else if(x>mid) change(i*2+1,x,y,s);
    else change(i*2,x,mid,s),change(i*2+1,mid+1,y,s);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
}
ll query(int i,int x,int y)
{

    int l=tree[i].l,r=tree[i].r;
    int mid=(l+r)>>1;
    if(tree[i].x!=0&&l!=r) change(i*2,l,mid,tree[i].x),change(i*2+1,mid+1,r,tree[i].x),tree[i].x=0;
    if(l>=x&&y>=r) return tree[i].sum;
    if(y<=mid) return query(i*2,x,y);
    else if(x>mid) return query(i*2+1,x,y);
    else return query(i*2,x,mid)+query(i*2+1,mid+1,y);
}
ll solvesum(int x)
{
    int f1=top[x],xx=0,yy=0;
    ll ans=0;
    while(f1!=1)
    {
        xx=mark[f1],yy=mark[x],x=fa[f1];
        ans+=query(1,xx,yy);
        f1=top[x];
    }
    ans+=query(1,1,mark[x]);
    return ans;
}
int main()
{
    int n,q,x,z;
    ll y;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&val[i]);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(size,0,sizeof(size));
    sum=fa[1]=dep[1]=0;
    dfs_1(1);
    dfs_2(1,1);
    build(1,1,n);
    for(int i=1;i<=n;i++) change(1,mark[i],mark[i],val[i]);
    while(q--)
    {
        scanf("%d%d",&z,&x);
        if(z==1)
        {
            scanf("%lld",&y);
            change(1,mark[x],mark[x],y);
        }
        else if(z==2)
        {
            scanf("%lld",&y);
            change(1,mark[x],R[x],y);
        }
        else cout<<solvesum(x)<<endl;
    }
    return 0;
}

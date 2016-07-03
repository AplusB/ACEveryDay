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
#define N 1000100
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
typedef long long LL;
#define mod 1000000007
using namespace std;
struct node
{
    int x,i,j,rankc,rankr;
}a[N];
int vis[N],rankc[N],rankr[N],sum,n,m,pre[N],fa[N];
bool markc[N],markr[N];
bool cmp(node a,node b)
{
    if(a.i==b.i) return a.x<b.x;
    return a.i<b.i;
}
bool cmp1(node a,node b)
{
    if(a.j==b.j) return a.x<b.x;
    return a.j<b.j;
}
bool cmp2(node a,node b)
{
    return a.x<b.x;
}
int fi(int x)
{
    if(pre[x]==-1) return x;
    return pre[x]=fi(pre[x]);
}
int main()
{
    int x;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&x);
            a[sum].x=x,a[sum].i=i,a[sum++].j=j;
        }
    sort(a,a+sum,cmp);
    memset(markc,0,sizeof(markc));
    memset(markr,0,sizeof(markr));
    memset(rankc,-1,sizeof(rankc));
    memset(rankr,-1,sizeof(rankr));
    memset(pre,-1,sizeof(pre));
    memset(fa,0,sizeof(fa));
    for(int i=0;i<sum;i++)
    {
        a[i].rankr=i-a[i].i*m;
        if(i-a[i].i*m==0) continue;
        rankr[a[i].i*m+a[i].j]=a[i-1].i*m+a[i-1].j;
        if(a[i-1].x!=a[i].x) markr[a[i].i*m+a[i].j]=1;
        else
        {
            int xx=fi(a[i-1].i*m+a[i-1].j),yy=fi(a[i].i*m+a[i].j);

            if(xx!=yy) pre[yy]=xx;
        }
    }
    sort(a,a+sum,cmp1);
    for(int i=0;i<sum;i++)
    {
        a[i].rankc=i-a[i].j*n;
        if(i-a[i].j*n==0) continue;
        rankc[a[i].i*m+a[i].j]=a[i-1].i*m+a[i-1].j;
        if(a[i-1].x!=a[i].x) markc[a[i].i*m+a[i].j]=1;
        else
        {
            int xx=fi(a[i-1].i*m+a[i-1].j),yy=fi(a[i].i*m+a[i].j);
            if(xx!=yy) pre[yy]=xx;
        }
    }
    sort(a,a+sum,cmp2);
    for(int i=0;i<sum;i++)
    {
        int x=a[i].i*m+a[i].j;
        int xx=fi(x);
        int temp=1;
        if(rankr[x]==0&&rankc[x]==0) temp=1;
        if(vis[rankr[x]]&&markr[x]) temp=max(temp,fa[fi(rankr[x])]+1);
        if(vis[rankc[x]]&&markc[x]) temp=max(temp,fa[fi(rankc[x])]+1);
        fa[xx]=max(fa[xx],temp);
        vis[x]=fa[xx];
      //  cout<<vis[x]<<" "<<xx<<" "<<a[i].i<<" "<<a[i].j<<" "<<a[i].x<<" "<<rankr[x]<<" "<<rankc[x]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cout<<fa[fi(i*m+j)]<<" ";cout<<endl;
    }
    return 0;
}
/*
5 5
100 101 100 100 100
1 1 1 1 1
99 99 99 99 99
101 101 101 101 101
2 2 2 2 2
*/

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
#define is(x) (son[fa[x]][1]==x)
char a[100100];
int n,size[150010],son[150000][2],p[150010],id[150010],val[150010];
int hash[150010],fa[150010],sum,root;
void update(int x)
{
    size[x]=size[son[x][0]]+size[son[x][1]]+1;
    hash[x]=hash[son[x][0]]+(ll)p[size[son[x][0]]]*val[x]%mod+(ll)hash[son[x][1]]*p[size[son[x][0]]+1]%mod;
    hash[x]%=mod;
}
void link(int x,int y,int d){son[y][d]=x;fa[x]=y;}
void rotate(int x)
{
    int y=fa[x],z=fa[y],zz=is(x),t=son[x][!zz];
    if(t) fa[t]=y;
    son[y][zz]=t;
    link(x,z,is(y));
    link(y,x,!zz);
    update(y);
}
void Splay(int x,int k)
{
    int y,z;
    while(fa[x]!=k)
    {
        y=fa[x],z=fa[y];
        if(z==k) rotate(x);
        else if(is(x)==is(y)) rotate(y),rotate(x);
        else rotate(x),rotate(x);
    }
    update(x);
    if(!k) root=x;
}
int select(int rank,int k)
{
    if(size[root]<rank) return -1;
    int x=root;
    while(size[son[x][0]]+1!=rank)
    {
        if(size[son[x][0]]+1>rank) x=son[x][0];
        else rank=rank-size[son[x][0]]-1,x=son[x][1];
    }
    Splay(x,k);
    return x;
}
void newnode(int &x,int y,int w)
{
    x=++n;son[x][0]=son[x][1]=0;
    val[x]=w,fa[x]=y,size[x]=1;
}
void change(int x,int p)
{
    x=select(x,0),val[x]=p,Splay(x,0);
}
void insert(int x,int p)
{
    int l=select(x,0),r=select(x+1,l);
    newnode(son[r][0],r,p);
    Splay(n,0);
}
int check(int a,int b,int l)
{
    int x;
    select(a-1,0),x=select(a+l,root);
    if(x==-1) return 0;
    int hash1=hash[son[x][0]];
    select(b-1,0),x=select(b+l,root);
    if(x==-1) return 0;
    int hash2=hash[son[x][0]];
    return hash1==hash2;
}
void build(int l,int r,int mid)
{
    if(l<mid) build(l,mid-1,l+mid-1>>1),fa[l+mid-1>>1]=mid,son[mid][0]=l+mid-1>>1;
    if(mid<r) build(mid+1,r,mid+1+r>>1),fa[mid+1+r>>1]=mid,son[mid][1]=mid+1+r>>1;
    val[mid]=id[mid],update(mid);
}
int main()
{
    scanf("%s",a);
    n=strlen(a)+2;p[0]=1;
    for(int i=1;i<=150004;i++) p[i]=p[i-1]*27%mod;
    for(int i=2;i<=n-1;i++) id[i]=a[i-2]-'a'+1;
    sum=n+2;root=(n+3)>>1;
    build(1,n,root);
    char c[10];
    int x,y,q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s%d",c,&x);
        if(c[0]=='Q')
        {
            scanf("%d",&y);
            int l=0,r=n,ans=0;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(check(x+1,y+1,mid)) ans=mid,l=mid+1;
                else r=mid-1;
            }
            cout<<ans<<endl;
        }
        else if(c[0]=='R') scanf("%s",c),change(x+1,c[0]-'a'+1);
        else scanf("%s",c),insert(x+1,c[0]-'a'+1);
    }
    return 0;
}

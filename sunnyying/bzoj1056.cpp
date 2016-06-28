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
#define N 300100
#define INF 20000000000
#define endl '\n'
#define ll long long
#define mod 1000000007
using namespace std;
#define is(x) (son[fa[x]][1]==x)
ll n,size[350010],son[350000][2],root,fa[N],val[N],flag;
string mark[N];
map<string,ll>A,B;
void link(ll x,ll y,ll d){son[y][d]=x;fa[x]=y;}
void rotate(ll x)
{
    ll y=fa[x],z=fa[y],zz=is(x),t=son[x][!zz];
    if(t) fa[t]=y;
    son[y][zz]=t;
    link(x,z,is(y));
    link(y,x,!zz);
    size[y]=size[son[y][0]]+size[son[y][1]]+1;
}
void Splay(ll x,ll k)
{
    ll y,z;
    while(fa[x]!=k)
    {
        y=fa[x],z=fa[y];
        if(z==k) rotate(x);
        else if(is(x)==is(y)) rotate(y),rotate(x);
        else rotate(x),rotate(x);
    }
    size[x]=size[son[x][0]]+size[son[x][1]]+1;
    if(!k) root=x;
}
ll select(ll rank,ll k)
{
    if(size[root]<rank) return -1;
    ll x=root;
    while(size[son[x][0]]+1!=rank)
    {
        if(size[son[x][0]]+1>rank) x=son[x][0];
        else rank=rank-size[son[x][0]]-1,x=son[x][1];
    }
    Splay(x,k);
    return x;
}
void insert(string s,ll x)
{
    n++;A[s]=1;flag++,val[n]=x;B[s]=n;
    if(root==0) root=n,fa[root]=0,son[root][0]=son[root][1]=0;
    else
    {
        int xx=root,yy=root;
        while(xx)
        {
            yy=xx;
            if(x<=val[xx]) xx=son[xx][1];
            else xx=son[xx][0];
        }
        if(x<=val[yy]) son[yy][1]=n;
        else son[yy][0]=n;
        fa[n]=yy;son[n][0]=son[n][1]=0;mark[n]=s;
    }
    Splay(n,0);
}
void del(ll x)
{
    flag--;
    select(x+2,0);select(x,root);
    son[son[root][0]][1]=0;
    size[son[root][0]]--;
    size[root]--;
}
void dfs(ll x)
{
    if(x==0) return;
    dfs(son[x][0]);
    cout<<" "<<mark[x];
    dfs(son[x][1]);
}
ll fi(ll x){Splay(x,0);return size[son[root][0]];}
int main()
{
  //  freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    char c[30];
    ll q;
    scanf("%lld",&q);
    insert("a",-INF);
    insert("b",INF);
    while(q--)
    {
        scanf("%s",c);
        string s;
        ll x=0;
        if(c[0]=='+')
        {
            scanf("%lld",&x);
            for(ll i=1;i<strlen(c);i++) s+=c[i];
            if(A[s]) del(fi(B[s])),A[s]=0;
            insert(s,x);
        }
        else if(c[0]=='?'&&c[1]>='A'&&c[1]<='Z')
        {
            for(ll i=1;i<strlen(c);i++) s+=c[i];
            cout<<fi(B[s])<<endl;
        }
        else
        {
            for(ll i=1;i<strlen(c);i++) x=x*10+c[i]-'0';x++;
            select(x,0);select(min(flag-1,x+9)+1,root);
            cout<<mark[root];
            dfs(son[son[root][1]][0]);
            cout<<endl;
        }
    }
    return 0;
}

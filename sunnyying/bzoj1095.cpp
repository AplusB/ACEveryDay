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
#define N 1250010
#define INF 12345678
#define endl '\n'
#define ll long long
#define mod 1000000007
using namespace std;
vector<int>v[N];
int a[N],sum,b[N],d[N];
struct node
{
    int lmx,lmi,rmx,rmi,l,r,dis,aa,bb;
}t[N];
void dfs(int x,int fa)
{
     a[sum++]=-1;a[sum++]=x;
     for(int i=0;i<v[x].size();i++)
     {
         int xx=v[x][i];
         if(xx==fa) continue;
         dfs(xx,x);
     }
     a[sum++]=0;
}
void update(int i)
{
    int a=t[i*2].aa,b=t[i*2].bb,c=t[i*2+1].aa,d=t[i*2+1].bb;
    t[i].dis=max(t[i*2].dis,t[i*2+1].dis);
    t[i].dis=max(max(t[i*2].lmx+t[i*2+1].rmi,t[i*2+1].rmx+t[i*2].lmi),t[i].dis);
    if(b>=c) t[i].aa=a,t[i].bb=b-c+d;
    else t[i].aa=a+c-b,t[i].bb=d;
    t[i].lmx=max(max(t[i*2].lmx-c+d,t[i*2].lmi+c+d),t[i*2+1].lmx);
    t[i].lmi=max(t[i*2].lmi+c-d,t[i*2+1].lmi);
    t[i].rmx=max(max(t[i*2+1].rmi+a+b,t[i*2+1].rmx+a-b),t[i*2].rmx);
    t[i].rmi=max(t[i*2+1].rmi+b-a,t[i*2].rmi);
}
void init(int l,int x)
{
    if(a[x]<=0) t[l].lmx=t[l].lmi=t[l].rmx=t[l].rmi=t[l].dis=-INF,t[l].aa=t[l].bb=0,a[x]==-1?t[l].bb++:t[l].aa++;
    else if(!b[a[x]]) t[l].lmx=t[l].lmi=t[l].rmx=t[l].rmi=0,t[l].dis=0,t[l].aa=t[l].bb=0,d[a[x]]=x;
    else t[l].lmx=t[l].lmi=t[l].rmx=t[l].rmi=t[l].dis=-INF,t[l].aa=t[l].bb=0,d[a[x]]=x;
}
void build(int i,int l,int r)
{
    t[i].l=l,t[i].r=r;
    int mid=(l+r)>>1;
    if(l==r){init(i,l);return;}
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    update(i);
}
void change(int i,int x)
{
    int l=t[i].l,r=t[i].r,mid=(l+r)>>1;
    if(l==r&&l==x){b[a[l]]^=1;init(i,l);return;}
    if(x<=(l+r>>1)) change(i*2,x);
    else change(i*2+1,x);
    update(i);
}
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int n,x,y,q;
    char s[5];
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sum=1;dfs(1,0);sum--;
    memset(b,0,sizeof(b));
    build(1,1,sum);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",s);
        if(s[0]=='G')
        {
            if(t[1].dis<0) cout<<-1<<endl;
            else cout<<t[1].dis<<endl;
        }
        else scanf("%d",&x),change(1,d[x]);
    }
    return 0;
}

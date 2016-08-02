/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=1e5+10;
int n,m;
struct node
{
    int f,len;
}t[4*N];

struct date
{
    int w,n;
} p[N];
struct line
{
    int a1,a2,b,f;
} li[4*N];
int cnt;

int cmp(date n1,date n2)
{
    if(n1.w==n2.w)
        return n1.n<n2.n;
    else
        return n1.w<n2.w;
}
int cmp2(line n1,line n2)
{
    return n1.b<n2.b;
}
void build(int o,int l,int r)
{
    t[o].f=0;
    t[o].len=0;
    if(l!=r)
    {
        int m=(l+r)/2;
        build(o*2,l,m);
        build(o*2+1,m+1,r);
    }
}
void get(int o,int l,int r)
{
    if(t[o].f) t[o].len=r-l+1;
    else
    {
        if(l==r) t[o].len=0;
        else t[o].len=t[o*2].len+t[o*2+1].len;
    }
}
void update(int o,int l,int r,int x,int y,int val)
{
    if(x<=l&&r<=y)
    {
        t[o].f+=val;
        get(o,l,r);
        return ;
    }
    int mid=(l+r)/2;
    if(x<=mid) update(o*2,l,mid,x,y,val);
    if(y>mid) update(o*2+1,mid+1,r,x,y,val);
    get(o,l,r);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long ans;
    int _,a1,a2,b;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&p[i].w);
            p[i].n=i;
        }
        sort(p+1,p+n+1,cmp);
        p[0].w=-1;
        p[n+1].w=-1;
        cnt=0;
        ans=0;
        for(int i=1; i<=n; i++)
        {
            int r=i+m-1;
            if(r>n) break;
            if(p[i].w==p[r].w)
            {
                if(p[i].w==p[i-1].w) a1=p[i-1].n+1;
                else a1=1;
                if(p[r].w==p[r+1].w) a2=p[r+1].n-1;
                else a2=n;
                li[cnt].a1=li[cnt+1].a1=a1;
                li[cnt].a2=li[cnt+1].a2=p[i].n;
                li[cnt].b=p[r].n;
                li[cnt+1].b=a2+1;
                li[cnt].f=1;
                li[cnt+1].f=-1;
                cnt+=2;
            }
        }
        build(1,1,n);
        sort(li,li+cnt,cmp2);
        /*for(int i=0;i<cnt;i++)
        {
            //printf("  %d %d %d %d\n",li[i].a1,li[i].a2,li[i].b,li[i].f);
        }*/
        for(int i=0;i<cnt-1;i++)
        {
            update(1,1,n,li[i].a1,li[i].a2,li[i].f);
            //if(li[i+1].b!=li[i].b)
                ans+=t[1].len*(li[i+1].b-li[i].b);
            //printf("  %d %d %d %d\n",li[i].a1,li[i].a2,li[i].b,li[i].f);
            //printf("%d %d\n",t[1].len,li[i+1].b-li[i].b);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

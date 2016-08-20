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
const int N=2e5+10;
int n,m,tot,has[N],in[N];
int sum[4*N];ll ans;
struct L
{
    int a1,a2,b1,b2,f;
}p[N];
struct node
{
    int x,y,l,r,f;
}gx[4*N],gy[4*N];

int cmp(node n1,node n2)
{
    return n1.y<n2.y;
}

void update(int o,int l,int r,int x,int v)
{
    if(l==r)
    {
        if(v==1)
            sum[o]++;
        else
            sum[o]--;
    }
    else
    {
        int mid=(l+r)/2;
        if(x<=mid) update(o*2,l,mid,x,v);
        else update(o*2+1,mid+1,r,x,v);
        sum[o]=sum[o*2]+sum[o*2+1];
    }
}
ll query(int o,int l,int r,int x,int y)
{
    if(x<=l&&y>=r)
    {
        return sum[o];
    }
    else
    {
        int mid=(l+r)/2;
        if(y<=mid) return query(o*2,l,mid,x,y);
        else if(x>mid) return query(o*2+1,mid+1,r,x,y);
        else return query(o*2,l,mid,x,y)+query(o*2+1,mid+1,r,x,y);
    }
}

/*
int bit(int x)
{
    return x&-x;
}
int query(int x)
{
    int ret=0;
    while(x)
    {
        ret+=sum[x];
        x-=bit(x);
    }
    return ret;
}

int add(int x,int v)
{
    while(x<=m+1)
    {
        sum[x]+=v;
        x+=bit(x);
    }
}
*/
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,a1,a2,b1,b2;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        tot=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
            in[tot++]=a1;in[tot++]=a2;
            if(a1==a2)
            {
                if(b1>b2) swap(b1,b2);
                p[i].a1=a1;p[i].b1=b1;p[i].a2=a2;p[i].b2=b2;p[i].f=0;
            }
            else
            {
                if(a1>a2) swap(a1,a2);
                p[i].a1=a1;p[i].b1=b1;p[i].a2=a2;p[i].b2=b2;p[i].f=1;
            }
        }
        m=0;
        has[0]=in[0];
        sort(in,in+tot);
        for(int i=1;i<tot;i++)
        {
            if(in[i]==in[i-1]) continue;
            has[++m]=in[i];
        }
        int tx,ty;
        tx=0;
        ty=0;
        for(int i=0;i<n;i++)
        {
            p[i].a1=lower_bound(has,has+m+1,p[i].a1)-has+1;
            p[i].a2=lower_bound(has,has+m+1,p[i].a2)-has+1;
            if(p[i].f==1)
            {
                node tmp;
                tmp.l=p[i].a1;
                tmp.r=p[i].a2;
                tmp.y=p[i].b1;
                gx[tx++]=tmp;
                //printf("%d %d %d\n",tmp.l,tmp.r,tmp.y);
            }
            else
            {
                node tmp;
                tmp.x=p[i].a1;
                tmp.y=p[i].b1;
                tmp.f=1;
                gy[ty++]=tmp;

                tmp.x=p[i].a1;
                tmp.y=p[i].b2+1;
                tmp.f=-1;
                gy[ty++]=tmp;
            }
        }
        memset(sum,0,sizeof(sum));
        sort(gx,gx+tx,cmp);
        sort(gy,gy+ty,cmp);
        ans=0;
        int j=0;
        for(int i=0;i<tx;i++)
        {
            while(gx[i].y>=gy[j].y&&j<ty)
            {
                update(1,1,m+1,gy[j].x,gy[j].f);
                //add(gy[j].x,gy[j].f);
                j++;
            }
            ans+=query(1,1,m+1,gx[i].l,gx[i].r);
            //ans+=query(gx[i].r)-query(gx[i].l-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e8+7;
const int INF=0x3f3f3f3f;

const int N=20025;
LL dis[N];
LL num[N];
struct asd{
    LL v;
    LL x;
};
int n;
asd q[N];
bool cmp(asd z1,asd z2)
{
    return z1.v<z2.v;
}

LL Sum(LL i,LL *x)
{
    LL ans=0;
    while(i>0)
    {
        ans+=x[i];
        i-=i&(-i);
    }
    return ans;
}
void add(LL i,LL t,LL *x)
{
    while(i<=N-10)
    {
        x[i]+=t;
        i+=i&(-i);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&q[i].v,&q[i].x);
    sort(q,q+n,cmp);
    memset(num,0,sizeof(num));
    memset(dis,0,sizeof(dis));
    LL ans=0;
    for(int i=0;i<n;i++)
    {
        LL x=q[i].x;
        LL le=Sum(x-1,num);
        LL ri=Sum(N-10,num)-Sum(x,num);
        ans+=q[i].v*(le*x-Sum(x-1,dis)+Sum(N-10,dis)-Sum(x,dis)-ri*x);
        add(x,1,num);
        add(x,x,dis);
    }
    printf("%lld\n",ans);
    return 0;
}


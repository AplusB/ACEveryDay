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

const int N=1e3+10;
int c[N];
int m,n,k;

struct asd{
    int x,y;
};
asd q[N*N];
bool cmp(asd a,asd b)
{
    if(a.x==b.x)return a.y<=b.y;
    else return a.x<b.x;
}

int Sum(int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=c[i];
        i-=i&(-i);
    }
    return ans;
}

void add(int i,int t)
{
    while(i<=N-2)
    {
        c[i]+=t;
        i+=i&(-i);
    }
}

int main()
{
    int t;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<k;i++)
            scanf("%d%d",&q[i].x,&q[i].y);

        sort(q,q+k,cmp);
        memset(c,0,sizeof(c));
        LL ans=0;
        for(int i=0;i<k;i++)
        {
            add(q[i].y,1);
            ans+=Sum(m)-Sum(q[i].y);
        }
        printf("Test case %d: %lld\n",cas++,ans);
    }
    return 0;
}





